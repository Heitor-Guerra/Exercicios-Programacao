from __future__ import annotations

import math

EARTH_RADIUS: int = 6378
PI: float = 3.141592


class Point:
    __lat: float
    __lng: float

    def __init__(self, lat: float, lng: float) -> None:
        self.__lat = lat
        self.__lng = lng

    @property
    def lat(self) -> float:
        return self.__lat

    @property
    def lng(self) -> float:
        return self.__lng

    def location(self) -> tuple[float, float]:
        return (self.__lat, self.__lng)

    def move(self, lat: float, lng: float) -> None:
        self.__lat = lat
        self.__lng = lng

    # Formula de Haversine
    def distance(self, point: Point) -> float:
        phi1 = math.radians(self.__lat)
        phi2 = math.radians(point.__lat)
        deltaPhi = math.radians(point.__lat - self.__lat)
        deltaLambda = math.radians(point.__lng - self.__lng)

        x: float = math.sin(deltaPhi / 2) ** 2
        y: float = math.sin(deltaLambda / 2) ** 2
        z: float = math.cos(phi1) * math.cos(phi2) * y
        return 2 * EARTH_RADIUS * math.asin(math.sqrt(x + z))
