/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gptbacktrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:22 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/03 16:02:29 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define MAX_ITEMS 3


// Représente une position sur la carte
struct Position {
  int x;
  int y;
};

// Représente un élément que vous devez récupérer sur la carte
struct Item {
  struct Position pos;
  bool collected;
};

// Représente la carte avec ses murs, sa position de départ et les éléments à récupérer
struct Map {
  char grid[MAP_WIDTH][MAP_HEIGHT];
  struct Position start;
  struct Item items[MAX_ITEMS];
  int numItems;
};

// Vérifie si la position est valide (à l'intérieur de la carte et pas un mur)
bool isValidPosition(struct Map *map, int x, int y) {
  if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
    return false; // Position en dehors de la carte
  }
  if (map->grid[x][y] == '#') {
    return false; // Mur
  }
  return true;
}

// Vérifie si tous les éléments ont été récupérés
bool allItemsCollected(struct Map *map) {
  for (int i = 0; i < map->numItems; i++) {
    if (!map->items[i].collected) {
      return false; // Il y a encore un élément non récupéré
    }
  }
  return true;
}

// Vérifie si la position donnée est la sortie
bool isExit(struct Map *map, int x, int y) {
  return map->grid[x][y] == 'E';
}

// Récupère un élément si la position en contient un
void collectItem(struct Map *map, int x, int y) {
  for (int i = 0; i < map->numItems; i++) {
    if (map->items[i].pos.x == x && map->items[i].pos.y == y && !map->items[i].collected) {
      map->items[i].collected = true;
      break;
    }
  }
}

// Fonction de backtracking qui vérifie s'il existe un chemin pour récupérer tous les éléments et atteindre la sortie
bool backtrack(struct Map *map, int x, int y, bool collectedItems[]) {
  // Si nous avons récupéré tous les éléments et atteint la sortie, le chemin est valide
  if (allItemsCollected(map) && isExit(map, x, y)) {
    return true;
  }

  // Si la position n'est pas valide ou si nous avons déjà visité cet élément, on ne peut pas continuer sur ce chemin
  if (!isValidPosition(map, x, y) || collectedItems[x * MAP_WIDTH + y]) {
    return false;
  }

  // Marque cet élément comme visité
  collectedItems[x * MAP_WIDTH + y] = true;

  // Récupère un éventuel élément à cet emplacement
  collectItem(map, x, y);

  // Explore les positions adjacentes
  if (backtrack(map, x + 1, y, collectedItems)) { // Droite
    return true;
  }
  if (backtrack(map, x - 1, y, collectedItems)) { // Gauche
    return true;
  }
  if (backtrack(map, x, y + 1, collectedItems)) { // Bas
    return true;
  }
  if (backtrack(map, x, y - 1, collectedItems)) { // Haut
    return true;
  }

  // Aucun chemin valide depuis cette position, on remet l'élément comme non visité et on abandonne ce chemin
  collectedItems[x * MAP_WIDTH + y] = false;
  return false;
}

int main(void) {
  struct Map map = {
  .grid = {
    "#########",
    "#S.#....#",
    "#.#.#..E#",
    "#.#.#...#",
    "#.#.#.#.#",
    "#.#.#.#.#",
    "#.#.#...#",
    "#...#...#",
    "#########"
  },
  .start = { .x = 1, .y = 0 },
  .items = {
    { .pos = { .x = 1, .y = 1 }, .collected = false },
    { .pos = { .x = 4, .y = 2 }, .collected = false },
    { .pos = { .x = 4, .y = 4 }, .collected = false }
  },
  .numItems = 3
};

  bool collectedItems[MAP_WIDTH * MAP_HEIGHT] = { 0 };

  if (backtrack(&map, map.start.x, map.start.y, collectedItems)) {
    printf("Il existe un chemin pour récupérer tous les éléments et atteindre la sortie.\n");
  } else {
    printf("Il n'existe pas de chemin pour récupérer tous les éléments et atteindre la sortie.\n");
  }

  return 0;
}