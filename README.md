<div align="center">

# 🕸️ MIUP — Algoritmos de Grafos

**Exercícios resolvidos de teoria de grafos para preparar a MIUP (Maratona Inter-Universitária de Programação)**

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
[![CSES](https://img.shields.io/badge/CSES-Graph%20Algorithms-ff6f00?style=for-the-badge)](https://cses.fi/problemset/)
![Resolvidos](https://img.shields.io/badge/resolvidos-29-success?style=for-the-badge)

</div>

---

## 📖 Sobre

Coleção de soluções em **C++** para problemas clássicos de grafos, maioritariamente da secção
*Graph Algorithms* do [CSES Problem Set](https://cses.fi/problemset/). Cada ficheiro começa com um
cabeçalho que descreve o problema, o algoritmo usado e a complexidade.

## 🧠 Algoritmos abordados

| Categoria | Técnicas |
| :--- | :--- |
| 🔍 **Travessias** | BFS, DFS, flood fill em grelhas, BFS multi-source |
| 🧩 **Conectividade** | Componentes conexas, grafos bipartidos, deteção de ciclos |
| 🛣️ **Caminhos mínimos** | Dijkstra, Bellman-Ford, Floyd-Warshall, k-shortest paths |
| 📐 **DAGs** | Ordenação topológica (Kahn), DP em DAGs |
| 🌲 **Árvores geradoras** | Kruskal, Union-Find (DSU) |
| 🔗 **Componentes fortemente conexas** | Kosaraju, 2-SAT |
| 🔁 **Grafos funcionais** | Binary Lifting, deteção de ciclos |
| ✉️ **Caminhos especiais** | Circuito Euleriano (Hierholzer) |
| 🤝 **Emparelhamentos** | Emparelhamento bipartido (algoritmo de Kuhn) |
| 🌊 **Fluxos** | Fluxo máximo (Edmonds-Karp), corte mínimo |

---

## 📚 Exercícios Resolvidos

### 🔍 Travessias (BFS / DFS)

| # | Problema | Algoritmo | Complexidade | Código |
| :-: | :--- | :--- | :-: | :--- |
| 1 | [Counting Rooms](https://cses.fi/problemset/task/1192) | BFS (flood fill), componentes conexas | `O(n·m)` | [`countingRooms.cpp`](./countingRooms.cpp) |
| 2 | [Labyrinth](https://cses.fi/problemset/task/1193) | BFS em grelha + reconstrução do caminho | `O(n·m)` | [`labyrinth.cpp`](./labyrinth.cpp) |
| 3 | [Building Roads](https://cses.fi/problemset/task/1666) | BFS, componentes conexas | `O(n+m)` | [`buildingRoads.cpp`](./buildingRoads.cpp) |
| 4 | [Message Route](https://cses.fi/problemset/task/1667) | BFS, caminho mínimo não pesado | `O(n+m)` | [`messageRoute.cpp`](./messageRoute.cpp) |
| 5 | [Building Teams](https://cses.fi/problemset/task/1668) | BFS, 2-coloração (bipartido) | `O(n+m)` | [`buildingTeams.cpp`](./buildingTeams.cpp) |
| 6 | [Round Trip](https://cses.fi/problemset/task/1669) | DFS, ciclo em grafo não dirigido | `O(n+m)` | [`roundTrip.cpp`](./roundTrip.cpp) |
| 7 | [Monsters](https://cses.fi/problemset/task/1194) | BFS multi-source (2 passagens) | `O(n·m)` | [`monsters.cpp`](./monsters.cpp) |

### 🛣️ Caminhos Mínimos

| # | Problema | Algoritmo | Complexidade | Código |
| :-: | :--- | :--- | :-: | :--- |
| 8 | [Shortest Routes I](https://cses.fi/problemset/task/1671) | Dijkstra | `O((n+m) log n)` | [`shortestRoute1.cpp`](./shortestRoute1.cpp) |
| 9 | [Shortest Routes II](https://cses.fi/problemset/task/1672) | Floyd-Warshall | `O(n³)` | [`shortestRouteII.cpp`](./shortestRouteII.cpp) |
| 10 | [High Score](https://cses.fi/problemset/task/1673) | Bellman-Ford (pesos negados) | `O(n·m)` | [`highScore.cpp`](./highScore.cpp) |
| 11 | [Flight Discount](https://cses.fi/problemset/task/1195) | Dijkstra com estados (cupão usado/não usado) | `O((n+m) log n)` | [`flightDiscount.cpp`](./flightDiscount.cpp) |
| 12 | [Cycle Finding](https://cses.fi/problemset/task/1197) | Bellman-Ford, ciclo negativo | `O(n·m)` | [`cycleFinding.cpp`](./cycleFinding.cpp) |
| 13 | [Flight Routes](https://cses.fi/problemset/task/1196) | Dijkstra modificado (k caminhos mais curtos) | `O(k·m log(k·m))` | [`flightRoutes.cpp`](./flightRoutes.cpp) |
| 14 | [Investigation](https://cses.fi/problemset/task/1202) | Dijkstra + DP (contagem, min/max voos) | `O((n+m) log n)` | [`investigation.cpp`](./investigation.cpp) |

### 📐 Grafos Dirigidos e DAGs

| # | Problema | Algoritmo | Complexidade | Código |
| :-: | :--- | :--- | :-: | :--- |
| 15 | [Round Trip II](https://cses.fi/problemset/task/1678) | DFS com pilha de recursão | `O(n+m)` | [`roundTripII.cpp`](./roundTripII.cpp) |
| 16 | [Course Schedule](https://cses.fi/problemset/task/1679) | Ordenação topológica (Kahn) | `O(n+m)` | [`courseSchedule.cpp`](./courseSchedule.cpp) |
| 17 | [Longest Flight Route](https://cses.fi/problemset/task/1680) | Kahn + DP de maior caminho | `O(n+m)` | [`longestFlightRoute.cpp`](./longestFlightRoute.cpp) |
| 18 | [Game Routes](https://cses.fi/problemset/task/1681) | Kahn + DP de contagem de caminhos | `O(n+m)` | [`gameRoutes.cpp`](./gameRoutes.cpp) |

### 🔁 Grafos Funcionais

| # | Problema | Algoritmo | Complexidade | Código |
| :-: | :--- | :--- | :-: | :--- |
| 19 | [Planets Queries I](https://cses.fi/problemset/task/1750) | Binary Lifting | `O((n+q) log k)` | [`planetsQueriesI.cpp`](./planetsQueriesI.cpp) |
| 20 | [Planets Cycles](https://cses.fi/problemset/task/1751) | Deteção de ciclos + propagação pela cauda | `O(n)` | [`planetsCycles.cpp`](./planetsCycles.cpp) |

### 🌲 Árvores Geradoras e Union-Find

| # | Problema | Algoritmo | Complexidade | Código |
| :-: | :--- | :--- | :-: | :--- |
| 21 | [Road Reparation](https://cses.fi/problemset/task/1675) | Kruskal + DSU | `O(m log m)` | [`roadReparation.cpp`](./roadReparation.cpp) |
| 22 | [Road Construction](https://cses.fi/problemset/task/1676) | DSU com tamanho das componentes | `O(m·α(n))` | [`roadConstruction.cpp`](./roadConstruction.cpp) |

### 🔗 Componentes Fortemente Conexas

| # | Problema | Algoritmo | Complexidade | Código |
| :-: | :--- | :--- | :-: | :--- |
| 23 | [Flight Routes Check](https://cses.fi/problemset/task/1682) | Kosaraju | `O(n+m)` | [`flightRouteCheck.cpp`](./flightRouteCheck.cpp) |
| 24 | [Planets and Kingdoms](https://cses.fi/problemset/task/1683) | Kosaraju | `O(n+m)` | [`planetsAndKingdoms.cpp`](./planetsAndKingdoms.cpp) |
| 25 | [Giant Pizza](https://cses.fi/problemset/task/1684) | 2-SAT (Kosaraju no grafo de implicações) | `O(n+m)` | [`giantPizza.cpp`](./giantPizza.cpp) |

### ✉️ Outros

| # | Problema | Algoritmo | Complexidade | Código |
| :-: | :--- | :--- | :-: | :--- |
| 26 | [Mail Delivery](https://cses.fi/problemset/task/1691) | Circuito Euleriano (Hierholzer) | `O(n+m)` | [`mailDelivery.cpp`](./mailDelivery.cpp) |
| 27 | [Subordinates](https://cses.fi/problemset/task/1674) | DFS em árvore (tamanho da subárvore) | `O(n)` | [`subordinate.cpp`](./subordinate.cpp) |

### 🤝 Emparelhamentos

| # | Problema | Algoritmo | Complexidade | Código |
| :-: | :--- | :--- | :-: | :--- |
| 28 | [School Dance](https://cses.fi/problemset/task/1696) | Emparelhamento bipartido (algoritmo de Kuhn) | `O(n·m)` | [`schoolDance.cpp`](./schoolDance.cpp) |

### 🌊 Fluxos e Cortes

| # | Problema | Algoritmo | Complexidade | Código |
| :-: | :--- | :--- | :-: | :--- |
| 29 | [Police Chase](https://cses.fi/problemset/task/1695) | Fluxo máximo (Edmonds-Karp) + corte mínimo | `O(n·(n+m))` | [`policeChase.cpp`](./policeChase.cpp) |

---

## ⚙️ Como compilar e correr

```bash
g++ -std=c++17 -O2 -Wall -o sol labyrinth.cpp
./sol < input.txt
```

O ficheiro [`template.cpp`](./template.cpp) serve de base para novos exercícios (I/O rápido, `MOD`, `INF`).

---

<div align="center">

*Desenvolvido em C++ para treino de Programação Competitiva* 💻

</div>
