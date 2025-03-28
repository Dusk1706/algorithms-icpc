using pi = pair<int, int>;
using vpi = vector<pi>;

const int MAXN = 1e5 + 5;

// Si se tiene un grafo sin peso, usar BFS.
vpi graph[MAXN]; // Grafo guardado como lista de adyascencia.
int dist[MAXN];

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

/*Llena un arreglo (dist), donde dist[i] indica la distancia mas corta 
que se tiene que recorrer desde un nodo 'x' para llegar al nodo 'i',
en caso de que 'i' no sea alcanzable desde 'x', dist[i] = -1

O(V + E log V)                                                      */
void dijkstra(int x) {
    F0R(i, MAXN)
    dist[i] = INF;
    dist[x] = 0;

    pqg<pi> pq;
    pq.emplace(0, x);
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (du > dist[u])
            continue;

        for (auto &[v, dv] : graph[u]) {
            if (du + dv < dist[v]) {
                dist[v] = du + dv;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Si la pq puede tener muchisimos elementos, utilizamos un set, en donde habra a lo mucho V elementos
    set<pi> pq;
    for (int u = 0; u < V; ++u)
        pq.emplace(dist[u], u);

    while (!pq.empty()) {
        auto [du, u] = *pq.begin();
        pq.erase(pq.begin());
        for (auto &[v, dv] : graph[u]) {
            if (du + dv < dist[v]) {
                pq.erase(pq.find({dist[v], v}));
                dist[v] = du + dv;
                pq.emplace(dist[v], v);
            }
        }
    }
}
