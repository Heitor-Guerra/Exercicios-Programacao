from point import Point


class Location(Point):
    __id: int

    def __init__(self, id: int, lat: float, lng: float) -> None:
        self.__id = id
        self.__area = 0
        super().__init__(lat, lng)

    def get_id(self) -> int:
        return self.__id
