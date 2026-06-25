package com.api.parkingcontrol.services;

import com.api.parkingcontrol.models.ParkingSpotModel;
import com.api.parkingcontrol.repositories.ParkingSpotRepository;
import jakarta.transaction.Transactional;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Service
public class ParkingSpotService {
  final ParkingSpotRepository parkingSpotRepository;

  public ParkingSpotService(ParkingSpotRepository parkingSpotRepository) {
    this.parkingSpotRepository = parkingSpotRepository;
  }

  @Transactional
  public ParkingSpotModel save (ParkingSpotModel parkingSpotModel) {
    return  parkingSpotRepository.save(parkingSpotModel);
  }

  @Transactional
  public void delete(UUID id) {
    Optional<ParkingSpotModel> ret = parkingSpotRepository.findById(id);
    if(ret.isPresent()) {
      parkingSpotRepository.deleteById(id);
    }
  }

  public boolean existsByLicensePlate(String licensePlate) {
    return !parkingSpotRepository.findByLicensePlateCar(licensePlate).isEmpty();
  }

  public boolean existsByOwner(String nameOwner) {
    return !parkingSpotRepository.findByNameOwner(nameOwner).isEmpty();
  }

  public List<ParkingSpotModel> findAll() {
    return parkingSpotRepository.findAll();
  }

  public Optional<ParkingSpotModel> findById(UUID id) {
    return parkingSpotRepository.findById(id);
  }
}
