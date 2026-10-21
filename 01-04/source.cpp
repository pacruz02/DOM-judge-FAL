// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FAL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// llano_acotado(w,p,q) = 
// Pt. it: p < i  < q : w[i] = w[i-1] /\ w[p] < w[q]

// P : { 1<= N <= 10^8 /\ 1 <= c <= N }

// Q : { b = Ex i,j : 0 <= i < j < N /\ j-i >= c : llano_acotado (v,i,j) }

// función que resuelve el problema
bool resolver(vector<int> const& v, int c) {
    int i = 1, l = 1, altura = v[0];
    while (i < v.size()) {
        if (v[i] == altura)
            l++;
        else {
            if(l >= c && v[i] > altura)
                return true;
            altura = v[i];
            l = 1;
        }
        i++;
    }
    return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N, c, m;

    cin >> N >> c;
    if (!N && !c)
        return false;

    vector<int> datos(N);
    
    for (int i = 0; i < N; i++) {
        cin >> m;
        datos[i] = m;
    }

    cout << (resolver(datos, c) ? "SI" : "NO") << '\n';

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
