from random import shuffle

from centroid import Centroid
from location import Location


def main() -> None:
    k: int = 2
    locations = []
    centroids = []

    # Grupo 1
    locations.append(Location(0, -20.361534, -40.296222))
    locations.append(Location(1, -20.365288, -40.310086))
    locations.append(Location(2, -20.354988, -40.303737))
    locations.append(Location(3, -20.344406, -40.296876))
    locations.append(Location(4, -20.337243, -40.283403))
    # Grupo 2
    locations.append(Location(5, -20.430411, -40.337817))
    locations.append(Location(6, -20.444607, -40.358498))
    locations.append(Location(7, -20.431155, -40.324999))

    shuffle(locations)
    # Inicialização dos Centróides
    for i in range(k):
        (lat, lng) = locations[i].location()
        centroids.append(Centroid(i, lat, lng))

    print("Configuração Inicial")
    for centroid in centroids:
        print(f"Centróide {centroid.get_id()}:")
        print(f"  Posição: ({centroid.lat}, {centroid.lng})")
        print(f"  Pontos: {[loc.get_id() for loc in centroid.children]}")
    print("\n")

    continue_loop = True
    while continue_loop:
        # Calcula as distância
        for location in locations:
            idx_min: int = 0
            dist_min: float = 99999999999

            for j, centroid in enumerate(centroids):
                dist = location.distance(centroid)
                if dist < dist_min:
                    dist_min = dist
                    idx_min = j

            centroids[idx_min].children.append(location)

        continue_loop = False
        for centroid in centroids:
            if centroid.update_position():
                continue_loop = True
                centroid.clear_children()

    print("Configuração Final: ")
    for centroid in centroids:
        print(f"Centróide {centroid.get_id()}:")
        print(f"  Posição: ({centroid.lat}, {centroid.lng})")
        print(f"  Pontos: {[loc.get_id() for loc in centroid.children]}")


if __name__ == "__main__":
    main()
