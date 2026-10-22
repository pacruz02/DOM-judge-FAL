// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FALL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector <int> const& v, int const l) {
    int unos = 0, sol = 1;
    int i = 0, j = l;
    while (j < v.size()) {
        if (v[i] == 0)
            unos++;
        else if (v[i] == 1)
            unos--;
        if (v[j] == 0)
            unos--;
        else if (v[j] == 1)
            unos++;
        if (!unos)
            sol++;

        i++, j++;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n, l;

    cin >> l >> n;

    vector<int> v(n);

    for (int& x : v) cin >> x;

    cout << resolver(v, l) << '\n';

}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}