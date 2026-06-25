package com.api.parkingcontrol.models;

import jakarta.persistence.*;

import java.io.Serial;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.UUID;


@Entity
@Table(name = "parking_spot")
public class ParkingSpotModel implements Serializable {
  @Serial
  private static final long serialVersionUID = 1L;

  @Id
  @GeneratedValue(strategy = GenerationType.AUTO)
  private UUID id;
  @Column(nullable=false, unique = true, length = 9)
  private String licensePlateCar;
  @Column(nullable=false, length = 20)
  private String brandCar;
  @Column(nullable=false, length = 20)
  private String modelCar;
  @Column(nullable=false, length = 20)
  private String colorCar;
  @Column(nullable=false)
  private LocalDateTime registrationDate;
  @Column(nullable=false, length = 40)
  private String nameOwner;

  public UUID getId() {
    return id;
  }

  public void setId(UUID id) {
    this.id = id;
  }

  public String getLicensePlateCar() {
    return licensePlateCar;
  }

  public void setLicensePlateCar(String licensePlateCar) {
    this.licensePlateCar = licensePlateCar;
  }

  public String getBrandCar() {
    return brandCar;
  }

  public void setBrandCar(String brandCar) {
    this.brandCar = brandCar;
  }

  public String getModelCar() {
    return modelCar;
  }

  public void setModelCar(String modelCar) {
    this.modelCar = modelCar;
  }

  public String getColorCar() {
    return colorCar;
  }

  public void setColorCar(String colorCar) {
    this.colorCar = colorCar;
  }

  public LocalDateTime getRegistrationDate() {
    return registrationDate;
  }

  public void setRegistrationDate(LocalDateTime registrationDate) {
    this.registrationDate = registrationDate;
  }

  public String getNameOwner() {
    return nameOwner;
  }

  public void setNameOwner(String nameOwner) {
    this.nameOwner = nameOwner;
  }
}
