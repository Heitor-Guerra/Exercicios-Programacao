import math
import sys
from random import random

import matplotlib.pyplot as plt
import numpy as np

from k_means.centroid import Centroid
from k_means.location import Location


def main() -> None:
    k: int = 2
    locations: list[list[Location]] = [
        # Grupo 0: Sem restrição
        [
            Location(0, -20.361534, -40.296222),  # -> Cluster 1
            Location(1, -20.365288, -40.310086),  # -> Cluster 1
            Location(2, -20.354988, -40.303737),  # -> Cluster 1
            Location(3, -20.442000, -40.345000),  # -> Cluster 0
            Location(4, -20.450000, -40.350000),  # -> Cluster 0
        ],
        # Grupo 1: Restringido ao Cluster 0
        [
            Location(
                5, -20.362000, -40.298000
            ),  # -> perto de Cluster 1, mas forçado em Cluster 0
            Location(6, -20.444607, -40.358498),  # -> Cluster 0
            Location(7, -20.431155, -40.324999),  # -> Cluster 0
        ],
        # Grupo 2: Restringido ao Cluster 1
        [
            Location(8, -20.351289, -40.308498),  # -> Cluster 1
            Location(
                9, -20.438000, -40.340000
            ),  # -> perto de Cluster 0, mas forçado em Cluster 1
            Location(
                10, -20.451000, -40.353000
            ),  # -> perto de Cluster 0, mas forçado em Cluster 1
        ],
    ]
    centroids: list[Centroid] = initialize_centroids(locations, k)

    print("Configuração Inicial")
    for centroid in centroids:
        print(centroid)
    print("\n")

    centroids = loop(locations, centroids)

    print("Configuração Final: ")
    for centroid in centroids:
        print(centroid)

    plot_clusters(locations, centroids)


def initialize_centroids(locations: list[list[Location]], k: int) -> list[Centroid]:
    centroids = []
    for i in range(k):
        (lat, lng) = locations[i + 1][
            math.floor(random() * len(locations[i + 1]))
        ].location()
        centroids.append(Centroid(i, lat, lng))

    return centroids


def loop(locations: list[list[Location]], centroids: list[Centroid]) -> list[Centroid]:
    continue_loop = True
    while continue_loop:
        for centroid in centroids:
            centroid.clear_children()

        # Inicializa os centroides com os valores fixos
        for location in locations[1]:
            centroids[0].children.append(location)

        for location in locations[2]:
            centroids[1].children.append(location)

        # Calcula as distância
        for location in locations[0]:
            idx_min: int = 0
            dist_min: float = sys.maxsize

            for j, centroid in enumerate(centroids):
                dist = location.distance(centroid)
                if dist < dist_min:
                    dist_min = dist
                    idx_min = j

            centroids[idx_min].children.append(location)

        continue_loop = False

        # Leva os centroides fixos em consideração

        for centroid in centroids:
            if centroid.update_position():
                continue_loop = True

        # Não leva os centroid fixos em consideração

        # for centroid in centroids:
        #     flexible_in_cluster = [
        #         loc for loc in centroid.children if loc.get_id() in [0, 1, 2, 3, 4]
        #     ]

        #     if flexible_in_cluster and centroid.update_position_locations(flexible_in_cluster):
        #         continue_loop = True

    return centroids


def plot_clusters(locations: list[list[Location]], centroids: list[Centroid]) -> None:
    fig, ax = plt.subplots(figsize=(10, 10))

    # Group 0: Flexible (blue)
    group0_lats = [loc.lat for loc in locations[0]]
    group0_lons = [loc.lng for loc in locations[0]]
    ax.scatter(
        group0_lons,
        group0_lats,
        c="blue",
        s=100,
        label="Group 0 (Flexible)",
        marker="o",
        alpha=0.7,
    )

    # Group 1: Constrained to Cluster 0 (red)
    group1_lats = [loc.lat for loc in locations[1]]
    group1_lons = [loc.lng for loc in locations[1]]
    ax.scatter(
        group1_lons,
        group1_lats,
        c="red",
        s=100,
        label="Group 1 (→ Cluster 0)",
        marker="s",
        alpha=0.7,
    )

    # Group 2: Constrained to Cluster 1 (green)
    group2_lats = [loc.lat for loc in locations[2]]
    group2_lons = [loc.lng for loc in locations[2]]
    ax.scatter(
        group2_lons,
        group2_lats,
        c="green",
        s=100,
        label="Group 2 (→ Cluster 1)",
        marker="^",
        alpha=0.7,
    )

    # Centroids (yellow stars)
    centroid_lats = [centroid.lat for centroid in centroids]
    centroid_lons = [centroid.lng for centroid in centroids]
    ax.scatter(
        centroid_lons,
        centroid_lats,
        c="yellow",
        s=500,
        label="Centroids",
        marker="*",
        edgecolors="black",
        linewidth=2,
        zorder=5,
    )

    # Add location IDs
    for group_idx, group in enumerate(locations):
        for loc in group:
            ax.annotate(
                f"{loc.get_id()}",
                (loc.lng, loc.lat),
                fontsize=8,
                xytext=(5, 5),
                textcoords="offset points",
            )

    # Add centroid IDs
    for i, centroid in enumerate(centroids):
        ax.annotate(
            f"C{i}",
            (centroid.lng, centroid.lat),
            fontsize=10,
            fontweight="bold",
            xytext=(5, -15),
            textcoords="offset points",
        )

    ax.set_xlabel("Longitude")
    ax.set_ylabel("Latitude")
    ax.set_title("K-Means Clustering with Constraints")
    ax.legend(loc="best")
    ax.grid(True, alpha=0.3)

    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()
