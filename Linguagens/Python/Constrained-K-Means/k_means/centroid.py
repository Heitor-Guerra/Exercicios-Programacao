from typing import overload, override

from .location import Location
from .point import Point


class Centroid(Point):
    __id: int

    def __init__(self, id: int, lat: float, lng: float) -> None:
        self.__id = id
        self.children: list[Location] = []
        super().__init__(lat, lng)

    def get_id(self) -> int:
        return self.__id

    def clear_children(self) -> None:
        self.children.clear()

    def update_position(self) -> bool:
        old_lat = self.lat
        old_lng = self.lng

        new_lat = sum(loc.lat for loc in self.children)
        new_lng = sum(loc.lng for loc in self.children)
        n = len(self.children)

        if n != 0:
            new_lat /= n
            new_lng /= n
        else:
            return False

        if abs(new_lat - old_lat) < 0.001 and abs(new_lng - old_lng) < 0.001:
            return False

        self.move(new_lat, new_lng)

        return True

    def update_position_locations(self, locations: list[Location]) -> bool:
        old_lat = self.lat
        old_lng = self.lng

        new_lat = sum(loc.lat for loc in locations)
        new_lng = sum(loc.lng for loc in locations)
        n = len(locations)

        if n != 0:
            new_lat /= n
            new_lng /= n
        else:
            return False

        if abs(new_lat - old_lat) < 0.001 and abs(new_lng - old_lng) < 0.001:
            return False

        self.move(new_lat, new_lng)

        return True

    @override
    def __str__(self) -> str:
        return f"""Centróide {self.get_id()}:
    Posição: ({self.lat}, {self.lng})
    Pontos: {[loc.get_id() for loc in self.children]}"""
