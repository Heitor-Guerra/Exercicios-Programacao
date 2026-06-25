package com.api.parkingcontrol.controllers;

import com.api.parkingcontrol.dtos.ParkingSpotDto;
import com.api.parkingcontrol.models.ParkingSpotModel;
import com.api.parkingcontrol.services.ParkingSpotService;
import jakarta.validation.Valid;
import org.springframework.beans.BeanUtils;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.List;
import java.util.Optional;
import java.util.UUID;

@RestController
@CrossOrigin(origins = "*", maxAge = 3600)
@RequestMapping("/parking_spot")
public class ParkingSpotController {

  final ParkingSpotService parkingSpotService;

  public ParkingSpotController(ParkingSpotService parkingSpotService) {
    this.parkingSpotService = parkingSpotService;
  }

  @PostMapping
  public ResponseEntity<Object> saveParkingSpot(@RequestBody @Valid ParkingSpotDto parkingSpotDto) {
    if(parkingSpotService.existsByLicensePlate(parkingSpotDto.getLicensePlateCar())) {
      return ResponseEntity.status(HttpStatus.CONFLICT).body("Conflict found: License Plate already registered!");
    } else if(parkingSpotService.existsByOwner(parkingSpotDto.getNameOwner())) {
      return ResponseEntity.status(HttpStatus.CONFLICT).body("Conflict found: Owner already registered!");
    }
    ParkingSpotModel parkingSpotModel = new ParkingSpotModel();
    BeanUtils.copyProperties(parkingSpotDto, parkingSpotModel);
    parkingSpotModel.setRegistrationDate(LocalDateTime.now(ZoneId.of("UTC")));
    return ResponseEntity.status(HttpStatus.CREATED).body(parkingSpotService.save(parkingSpotModel)); }

  @GetMapping
  public ResponseEntity<List<ParkingSpotModel>> getAllParkingSpots() {
    return ResponseEntity.status(HttpStatus.OK).body(parkingSpotService.findAll());
  }

  @GetMapping("/{id}")
  public ResponseEntity<Object> getParkingByID(@PathVariable UUID id) {
    Optional<ParkingSpotModel> parkingSpotModel = parkingSpotService.findById(id);
    if(parkingSpotModel.isEmpty()) {
      return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Id not found");
    }
    return ResponseEntity.status(HttpStatus.OK).body(parkingSpotModel.get());
  }

  @DeleteMapping("/{id}")
  public ResponseEntity<String> deleteParkingByID(@PathVariable UUID id) {
    Optional<ParkingSpotModel> parkingSpotModel = parkingSpotService.findById(id);
    if(parkingSpotModel.isEmpty()) {
      return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Id not found");
    }
    parkingSpotService.delete(id);
    return ResponseEntity.status(HttpStatus.OK).body("Parking Spot sucessuflly deleted");
  }

  @PutMapping("/{id}")
  public ResponseEntity<Object> updateParkingSpot(@PathVariable UUID id, @RequestBody @Valid ParkingSpotDto parkingSpotDto) {
    Optional<ParkingSpotModel> parkingSpotModel = parkingSpotService.findById(id);
    if(parkingSpotModel.isEmpty()) {
      return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Id not found");
    }
    ParkingSpotModel parkingSpotModel1 = new ParkingSpotModel();
    BeanUtils.copyProperties(parkingSpotDto, parkingSpotModel1);
    parkingSpotModel1.setId(parkingSpotModel.get().getId());
    parkingSpotModel1.setRegistrationDate(parkingSpotModel.get().getRegistrationDate());
    return ResponseEntity.status(HttpStatus.OK).body(parkingSpotService.save(parkingSpotModel1));
  }


}