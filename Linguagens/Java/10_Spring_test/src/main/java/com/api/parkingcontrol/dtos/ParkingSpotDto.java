package com.api.parkingcontrol.dtos;

import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Size;


public class ParkingSpotDto {
  @NotBlank
  @Size(max = 9)
  private String licensePlateCar;
  @NotBlank
  private String brandCar;
  @NotBlank
  private String modelCar;
  @NotBlank
  private String colorCar;
  @NotBlank
  private String nameOwner;

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

  public String getNameOwner() {
    return nameOwner;
  }

  public void setNameOwner(String nameOwner) {
    this.nameOwner = nameOwner;
  }
}
