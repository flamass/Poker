// Felipe Lamas Silva
// Ingeniería Civil en Telecomunicaciones
// Universidad de Concepción

#include <iostream>     // cout.
#include <fstream>      // ifstream.
#include <vector>       // vector.
#include <algorithm>    // sort.
#include <numeric>      // iota.
#include <string>       // string.
#include <utility>      // pair.
#include <iomanip>      // setw.

using namespace std;

class Carta
{
    friend istream& operator>>(istream&, Carta&);
public:
    // Funciones de acceso.
    char n() const
    {
        return numero;
    }
    char p() const
    {
        return pinta;
    }
    // Constructor vacio.
    Carta(){}
    // Constructor con argumentos.
    Carta(char n, char p)
    {
        numero = n;
        pinta = p;
    }
private:
    char numero;
    char pinta;
};

class Mano: public Carta
{
    friend istream& operator>>(istream&, Mano&);
public:
    // Funciones de acceso.
    Carta c1() const
    {
        return carta1;
    }
    Carta c2() const
    {
        return carta2;
    }
    Carta c3() const
    {
        return carta3;
    }
    Carta c4() const
    {
        return carta4;
    }
    Carta c5() const
    {
        return carta5;
    }
    // Constructor vacio.
    Mano(){}
    // Constructor con argumentos.
    Mano(Carta c1, Carta c2, Carta c3, Carta c4, Carta c5)
    {
        carta1 = c1;
        carta2 = c2;
        carta3 = c3;
        carta4 = c4;
        carta5 = c5;
    }
private:
    Carta carta1, carta2, carta3, carta4, carta5;
};

istream& operator>>(istream& in, Carta& c)
{
    return in >> c.numero >> c.pinta;
}

istream& operator>>(istream& in, Mano& m)
{
    return in >> m.carta1 >> m.carta2 >> m.carta3 >> m.carta4 >> m.carta5;
}

ostream& operator<<(ostream& out, const Carta& c)
{
    return out << c.n() << c.p();
}

ostream& operator<<(ostream& out, const Mano& m)
{
    return out << m.c1() << ' ' << m.c2() << ' ' << m.c3() << ' ' << m.c4() << ' ' << m.c5() << ' ';
}

bool operator==(const Carta& c1, const Carta& c2)
{
    return c1.n() == c2.n() && c1.p() == c2.p();
}

bool operator!=(const Carta& c1, const Carta& c2)
{
    return !(c1 == c2);
}

bool operator<(const Carta& c1, const Carta& c2)
{
    unsigned int n1, n2;
    if(c1.n() == '0')
    {
        n1 = 10;
    }
    else if(c1.n() == 'J')
    {
        n1 = 11;
    }
    else if(c1.n() == 'Q')
    {
        n1 = 12;
    }
    else if(c1.n() == 'K')
    {
        n1 = 13;
    }
    else if(c1.n() == 'A')
    {
        n1 = 14;
    }
    else
    {
        n1 = c1.n() - 48;
    }

    if(c2.n() == '0')
    {
        n2 = 10;
    }
    else if(c2.n() == 'J')
    {
        n2 = 11;
    }
    else if(c2.n() == 'Q')
    {
        n2 = 12;
    }
    else if(c2.n() == 'K')
    {
        n2 = 13;
    }
    else if(c2.n() == 'A')
    {
        n2 = 14;
    }
    else
    {
        n2 = c2.n() - 48;
    }

    return n1 < n2;
}

bool operator>(const Carta& c1, const Carta& c2)
{
    unsigned int n1, n2;
    if(c1.n() == '0')
    {
        n1 = 10;
    }
    else if(c1.n() == 'J')
    {
        n1 = 11;
    }
    else if(c1.n() == 'Q')
    {
        n1 = 12;
    }
    else if(c1.n() == 'K')
    {
        n1 = 13;
    }
    else if(c1.n() == 'A')
    {
        n1 = 14;
    }
    else
    {
        n1 = c1.n() - 48;
    }

    if(c2.n() == '0')
    {
        n2 = 10;
    }
    else if(c2.n() == 'J')
    {
        n2 = 11;
    }
    else if(c2.n() == 'Q')
    {
        n2 = 12;
    }
    else if(c2.n() == 'K')
    {
        n2 = 13;
    }
    else if(c2.n() == 'A')
    {
        n2 = 14;
    }
    else
    {
        n2 = c2.n() - 48;
    }

    return n1 > n2;
}

bool operator<=(const Carta& c1, const Carta& c2)
{
    return c1 < c2 || c1 == c2;
}

bool operator>=(const Carta& c1, const Carta& c2)
{
    return c1 > c2 || c1 == c2;
}

bool compara(const Carta& c1, const Carta& c2)
{
    return c1 < c2;
}

void ordena(Mano& m)
{
    vector<Carta> manoVec;
    manoVec.push_back(m.c1());
    manoVec.push_back(m.c2());
    manoVec.push_back(m.c3());
    manoVec.push_back(m.c4());
    manoVec.push_back(m.c5());
    sort(manoVec.begin(), manoVec.end(), compara);
    Mano mAux(manoVec.at(0), manoVec.at(1), manoVec.at(2), manoVec.at(3), manoVec.at(4));
    m = mAux;
}

unsigned int convertidorNumeroCartaInt(char nChar)
{
    unsigned int nRet;
    if(nChar == '0')
    {
        nRet = 10;
    }
    else if(nChar == 'J')
    {
        nRet = 11;
    }
    else if(nChar == 'Q')
    {
        nRet = 12;
    }
    else if(nChar == 'K')
    {
        nRet = 13;
    }
    else if(nChar == 'A')
    {
        nRet = 14;
    }
    else
    {
        nRet = nChar - 48;
    }

    return nRet;
}

bool escaleraReal(const Mano& m) // Importante!!!: Funcion escaleraReal() recibe mano ordenada.
{
    // Cartas predeterminadas.
    Carta diezCorazon('0', 'C'), JCorazon('J', 'C'), QCorazon('Q', 'C'), KCorazon('K', 'C'), asCorazon('A', 'C');
    Carta diezDiamante('0', 'D'), JDiamante('J', 'D'), QDiamante('Q', 'D'), KDiamante('K', 'D'), asDiamante('A', 'D');
    Carta diezPica('0', 'P'), JPica('J', 'P'), QPica('Q', 'P'), KPica('K', 'P'), asPica('A', 'P');
    Carta diezTrebol('0', 'T'), JTrebol('J', 'T'), QTrebol('Q', 'T'), KTrebol('K', 'T'), asTrebol('A', 'T');

    if(m.c1() == diezCorazon && m.c2() == JCorazon && m.c3() == QCorazon && m.c4() == KCorazon && m.c5() == asCorazon)
    {
        return true;
    }
    else if(m.c1() == diezDiamante && m.c2() == JDiamante && m.c3() == QDiamante && m.c4() == KDiamante && m.c5() == asDiamante)
    {
        return true;
    }
    else if(m.c1() == diezPica && m.c2() == JPica && m.c3() == QPica && m.c4() == KPica && m.c5() == asPica)
    {
        return true;
    }
    else if(m.c1() == diezTrebol && m.c2() == JTrebol && m.c3() == QTrebol && m.c4() == KTrebol && m.c5() == asTrebol)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool escaleraDeColor(const Mano& m) // Importante!!!: Funcion escaleraDeColor() recibe mano ordenada.
{
    vector<unsigned int> verificador(5);
    iota(verificador.begin(), verificador.end(), convertidorNumeroCartaInt(m.c1().n()));
    if((verificador.at(0) == convertidorNumeroCartaInt(m.c1().n()) && verificador.at(1) == convertidorNumeroCartaInt(m.c2().n())
        && verificador.at(2) == convertidorNumeroCartaInt(m.c3().n()) && verificador.at(3) == convertidorNumeroCartaInt(m.c4().n())
        && verificador.at(4) == convertidorNumeroCartaInt(m.c5().n())) && (m.c1().p() == m.c2().p()
        && m.c2().p() == m.c3().p() && m.c3().p() == m.c4().p() && m.c4().p() == m.c5().p()))
    {
        return true;
    }
    else if((m.c1().n() == '2' && m.c2().n() == '3' && m.c3().n() == '4' && m.c4().n() == '5' && m.c5().n() == 'A')
            && (m.c1().p() == m.c2().p() && m.c2().p() == m.c3().p() && m.c3().p() == m.c4().p() && m.c4().p() == m.c5().p()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool poker(const Mano& m) // Importante!!!: Funcion poker() recibe mano ordenada.
{
    if((m.c1().n() == m.c2().n() && m.c2().n() == m.c3().n() && m.c3().n() == m.c4().n())
       || (m.c2().n() == m.c3().n() && m.c3().n() == m.c4().n() && m.c4().n() == m.c5().n()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool full(const Mano& m) // Importante!!!: Funcion full() recibe mano ordenada.
{
    if(((m.c1().n() == m.c2().n() && m.c2().n() == m.c3().n()) && (m.c4().n() == m.c5().n()))
       || ((m.c1().n() == m.c2().n()) && (m.c3().n() == m.c4().n() && m.c4().n() == m.c5().n())))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool color(const Mano& m) // Importante!!!: Funcion color() recibe mano ordenada.
{
    if(m.c1().p() == m.c2().p() && m.c2().p() == m.c3().p() && m.c3().p() == m.c4().p() && m.c4().p() == m.c5().p())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool escalera(const Mano& m) // Importante!!!: Funcion escalera() recibe mano ordenada.
{
    vector<unsigned int> verificador(5);
    iota(verificador.begin(), verificador.end(), convertidorNumeroCartaInt(m.c1().n()));
    if(verificador.at(0) == convertidorNumeroCartaInt(m.c1().n()) && verificador.at(1) == convertidorNumeroCartaInt(m.c2().n())
        && verificador.at(2) == convertidorNumeroCartaInt(m.c3().n()) && verificador.at(3) == convertidorNumeroCartaInt(m.c4().n())
        && verificador.at(4) == convertidorNumeroCartaInt(m.c5().n()))
    {
        return true;
    }
    else if(m.c1().n() == '2' && m.c2().n() == '3' && m.c3().n() == '4' && m.c4().n() == '5' && m.c5().n() == 'A')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool trio(const Mano& m) // Importante!!!: Funcion trio() recibe mano ordenada.
{
    if((m.c1().n() == m.c2().n() && m.c2().n() == m.c3().n()) || (m.c2().n() == m.c3().n() && m.c3().n() == m.c4().n())
       || (m.c3().n() == m.c4().n() && m.c4().n() == m.c5().n()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool dosPares(const Mano& m) // Importante!!!: Funcion dosPares() recibe mano ordenada.
{
    if((m.c1().n() == m.c2().n() && m.c3().n() == m.c4().n()) || (m.c1().n() == m.c2().n() && m.c4().n() == m.c5().n())
       || (m.c2().n() == m.c3().n() && m.c4().n() == m.c5().n()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool unPar(const Mano& m) // Importante!!!: Funcion unPar() recibe mano ordenada.
{
    if(m.c1().n() == m.c2().n() || m.c2().n() == m.c3().n() || m.c3().n() == m.c4().n() || m.c4().n() == m.c5().n())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Mano m1, m2;

    ifstream entrada("poker.txt");

    pair<string, string> juegosIndividuales;
    vector<pair<string, string> > partidas;

    for(int i = 1; i <= 1000; ++i)
    {
        entrada >> m1 >> m2;
        ordena(m1);
        ordena(m2);

        if(escaleraReal(m1) == true && escaleraReal(m2) == true)
        {
            juegosIndividuales = make_pair("Empate", "Ambos jugadores tienen Escalera Real");
            partidas.push_back(juegosIndividuales);
        }
        else if(escaleraReal(m1))
        {
            juegosIndividuales = make_pair("Gana Jugador 1", "Por Escalera Real");
            partidas.push_back(juegosIndividuales);
        }
        else if(escaleraReal(m2))
        {
            juegosIndividuales = make_pair("Gana Jugador 2", "Por Escalera Real");
            partidas.push_back(juegosIndividuales);
        }
        else if(escaleraDeColor(m1) == true && escaleraDeColor(m2) == true)
        {
            if(m1.c5() > m2.c5())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "Por Escalera de Color de mayor valor");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c5() < m2.c5())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "Por Escalera de Color de mayor valor");
                partidas.push_back(juegosIndividuales);
            }
            else
            {
                juegosIndividuales = make_pair("Empate", "Jugadores tienen Escaleras de Color del mismo valor");
                partidas.push_back(juegosIndividuales);
            }
        }
        else if(escaleraDeColor(m1))
        {
            juegosIndividuales = make_pair("Gana Jugador 1", "Por Escalera de Color");
            partidas.push_back(juegosIndividuales);
        }
        else if(escaleraDeColor(m2))
        {
            juegosIndividuales = make_pair("Gana Jugador 2", "Por Escalera de Color");
            partidas.push_back(juegosIndividuales);
        }
        else if(poker(m1) == true && poker(m2) == true)
        {
            if(m1.c1().n() == m1.c2().n() && m2.c1().n() == m2.c2().n())
            {
                if(m1.c1() > m2.c1())
                {
                    juegosIndividuales = make_pair("Gana Jugador 1", "Por Póker de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
                else if(m1.c1() < m2.c1())
                {
                    juegosIndividuales = make_pair("Gana Jugador 2", "Por Póker de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
            }
            else if(m1.c1().n() == m1.c2().n() && m2.c4().n() == m2.c5().n())
            {
                if(m1.c1() > m2.c5())
                {
                    juegosIndividuales = make_pair("Gana Jugador 1", "Por Póker de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
                else if(m1.c1() < m2.c5())
                {
                    juegosIndividuales = make_pair("Gana Jugador 2", "Por Póker de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
            }
            else if(m1.c4().n() == m1.c5().n() && m2.c1().n() == m2.c2().n())
            {
                if(m1.c5() > m2.c1())
                {
                    juegosIndividuales = make_pair("Gana Jugador 1", "Por Póker de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
                else if(m1.c5() < m2.c1())
                {
                    juegosIndividuales = make_pair("Gana Jugador 2", "Por Póker de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
            }
            else
            {
                if(m1.c5() > m2.c5())
                {
                    juegosIndividuales = make_pair("Gana Jugador 1", "Por Póker de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
                else if(m1.c5() < m2.c5())
                {
                    juegosIndividuales = make_pair("Gana Jugador 2", "Por Póker de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
            }
        }
        else if(poker(m1))
        {
            juegosIndividuales = make_pair("Gana Jugador 1", "Por Póker");
            partidas.push_back(juegosIndividuales);
        }
        else if(poker(m2))
        {
            juegosIndividuales = make_pair("Gana Jugador 2", "Por Póker");
            partidas.push_back(juegosIndividuales);
        }
        else if(full(m1) == true && full(m2) == true)
        {
            if((m1.c1().n() == m1.c2().n() && m1.c2().n() == m1.c3().n()) &&
               (m2.c1().n() == m2.c2().n() && m2.c2().n() == m2.c3().n()))
            {
                if(m1.c1() > m2.c1())
                {
                    juegosIndividuales = make_pair("Gana Jugador 1", "Por Full con trío de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
                else
                {
                    juegosIndividuales = make_pair("Gana Jugador 2", "Por Full con trío de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
            }
            else if((m1.c1().n() == m1.c2().n() && m1.c2().n() == m1.c3().n()) &&
                    (m2.c5().n() == m2.c4().n() && m2.c4().n() == m2.c3().n()))
            {
                if(m1.c1() > m2.c5())
                {
                    juegosIndividuales = make_pair("Gana Jugador 1", "Por Full con trío de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
                else
                {
                    juegosIndividuales = make_pair("Gana Jugador 2", "Por Full con trío de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
            }
            else if((m1.c5().n() == m1.c4().n() && m1.c4().n() == m1.c3().n()) &&
                    (m2.c1().n() == m2.c2().n() && m2.c2().n() == m2.c3().n()))
            {
                if(m1.c5() > m2.c1())
                {
                    juegosIndividuales = make_pair("Gana Jugador 1", "Por Full con trío de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
                else
                {
                    juegosIndividuales = make_pair("Gana Jugador 2", "Por Full con trío de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
            }
            else
            {
                if(m1.c5() > m2.c5())
                {
                    juegosIndividuales = make_pair("Gana Jugador 1", "Por Full con trío de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
                else
                {
                    juegosIndividuales = make_pair("Gana Jugador 2", "Por Full con trío de mayor valor");
                    partidas.push_back(juegosIndividuales);
                }
            }
        }
        else if(full(m1))
        {
            juegosIndividuales = make_pair("Gana Jugador 1", "Por Full");
            partidas.push_back(juegosIndividuales);
        }
        else if(full(m2))
        {
            juegosIndividuales = make_pair("Gana Jugador 2", "Por Full");
            partidas.push_back(juegosIndividuales);
        }
        else if(color(m1) == true && color(m2) == true)
        {
            if(m1.c5() > m2.c5())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "Por Color con carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c5() < m2.c5())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "Por Color con carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c4() > m2.c4())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "Por Color con segunda carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c4() < m2.c4())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "Por Color con segunda carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c3() > m2.c3())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "Por Color con tercera carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c3() < m2.c3())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "Por Color con tercera carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c2() > m2.c2())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "Por Color con cuarta carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c2() < m2.c2())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "Por Color con cuarta carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c1() > m2.c1())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "Por Color con quinta carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c1() < m2.c1())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "Por Color con quinta carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else
            {
                juegosIndividuales = make_pair("Empate", "Ambos jugadores tienen Color con cartas del mismo valor");
                partidas.push_back(juegosIndividuales);
            }
        }
        else if(color(m1))
        {
            juegosIndividuales = make_pair("Gana Jugador 1", "Por Color");
            partidas.push_back(juegosIndividuales);
        }
        else if(color(m2))
        {
            juegosIndividuales = make_pair("Gana Jugador 2", "Por Color");
            partidas.push_back(juegosIndividuales);
        }
        else if(escalera(m1) == true && escalera(m2) == true)
        {
            if(m1.c5() > m2.c5())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "Por Escalera de mayor valor");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c5() < m2.c5())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "Por Escalera de mayor valor");
                partidas.push_back(juegosIndividuales);
            }
            else
            {
                juegosIndividuales = make_pair("Empate", "Jugadores poseen Escaleras de igual valor");
                partidas.push_back(juegosIndividuales);
            }
        }
        else if(escalera(m1))
        {
            juegosIndividuales = make_pair("Gana Jugador 1", "Por Escalera");
            partidas.push_back(juegosIndividuales);
        }
        else if(escalera(m2))
        {
            juegosIndividuales = make_pair("Gana Jugador 2", "Por Escalera");
            partidas.push_back(juegosIndividuales);
        }
        else if(trio(m1) == true && trio(m2) == true)
        {
            Carta cVerificadora1, cVerificadora2;
            if(m1.c1().n() == m1.c2().n())
            {
                cVerificadora1 = m1.c1();
            }
            else if(m1.c2().n() == m1.c3().n())
            {
                cVerificadora1 = m1.c2();
            }
            else
            {
                cVerificadora1 = m1.c3();
            }

            if(m2.c1().n() == m2.c2().n())
            {
                cVerificadora2 = m2.c1();
            }
            else if(m2.c2().n() == m2.c3().n())
            {
                cVerificadora2 = m2.c2();
            }
            else
            {
                cVerificadora2 = m2.c3();
            }
            if(cVerificadora1 > cVerificadora2)
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "Por Trío de mayor valor");
                partidas.push_back(juegosIndividuales);
            }
            else if(cVerificadora1 < cVerificadora2)
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "Por Trío de mayor valor");
                partidas.push_back(juegosIndividuales);
            }
        }
        else if(trio(m1))
        {
            juegosIndividuales = make_pair("Gana Jugador 1", "Por Trío");
            partidas.push_back(juegosIndividuales);
        }
        else if(trio(m2))
        {
            juegosIndividuales = make_pair("Gana Jugador 2", "Por Trío");
            partidas.push_back(juegosIndividuales);
        }
        else if(dosPares(m1) == true && dosPares(m2) == true)
        {
            Carta cVerificadora1Mano1, cVerificadora2Mano1;
            Carta cVerificadora1Mano2, cVerificadora2Mano2;
            if(m1.c1().n() == m1.c2().n())
            {
                cVerificadora1Mano1 = m1.c1();
                if(m1.c3().n() == m1.c4().n())
                {
                    cVerificadora2Mano1 = m1.c3();
                }
                else
                {
                    cVerificadora2Mano1 = m1.c4();
                }
            }
            else
            {
                cVerificadora1Mano1 = m1.c2();
                cVerificadora2Mano1 = m1.c4();
            }

            if(m2.c1().n() == m2.c2().n())
            {
                cVerificadora1Mano2 = m2.c1();
                if(m2.c3().n() == m2.c4().n())
                {
                    cVerificadora2Mano2 = m2.c3();
                }
                else
                {
                    cVerificadora2Mano2 = m2.c4();
                }
            }
            else
            {
                cVerificadora1Mano2 = m2.c2();
                cVerificadora2Mano2 = m2.c4();
            }

            if(cVerificadora1Mano1 == cVerificadora1Mano2 && cVerificadora2Mano1 == cVerificadora2Mano2)
            {
                int sumaM1 = convertidorNumeroCartaInt(m1.c1().n()) + convertidorNumeroCartaInt(m1.c2().n())
                + convertidorNumeroCartaInt(m1.c3().n()) + convertidorNumeroCartaInt(m1.c4().n())
                + convertidorNumeroCartaInt(m1.c5().n());
                int sumaM2 = convertidorNumeroCartaInt(m2.c1().n()) + convertidorNumeroCartaInt(m2.c2().n())
                + convertidorNumeroCartaInt(m2.c3().n()) + convertidorNumeroCartaInt(m2.c4().n())
                + convertidorNumeroCartaInt(m2.c5().n());
                if(sumaM1 > sumaM2)
                {
                    juegosIndividuales = make_pair("Gana Jugador 1", "Por Dos Pares con carta restante mayor");
                    partidas.push_back(juegosIndividuales);
                }
                else if(sumaM1 < sumaM2)
                {
                    juegosIndividuales = make_pair("Gana Jugador 2", "Por Dos Pares con carta restante mayor");
                    partidas.push_back(juegosIndividuales);
                }
                else
                {
                    juegosIndividuales = make_pair("Empate", "Jugadores poseen Dos Pares iguales y carta restante igual");
                    partidas.push_back(juegosIndividuales);
                }
            }
            else if(cVerificadora2Mano1 > cVerificadora2Mano2)
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "Por Dos Pares con par más alto");
                partidas.push_back(juegosIndividuales);
            }
            else if(cVerificadora2Mano1 < cVerificadora2Mano2)
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "Por Dos Pares con par más alto");
                partidas.push_back(juegosIndividuales);
            }
            else
            {
                if(cVerificadora1Mano1 > cVerificadora1Mano2)
                {
                    juegosIndividuales = make_pair("Gana Jugador 1", "Por Dos Pares con segundo par más alto");
                    partidas.push_back(juegosIndividuales);
                }
                else
                {
                    juegosIndividuales = make_pair("Gana Jugador 2", "Por Dos Pares con segundo par más alto");
                    partidas.push_back(juegosIndividuales);
                }
            }
        }
        else if(dosPares(m1))
        {
            juegosIndividuales = make_pair("Gana Jugador 1", "Por Dos Pares");
            partidas.push_back(juegosIndividuales);
        }
        else if(dosPares(m2))
        {
            juegosIndividuales = make_pair("Gana Jugador 2", "Por Dos Pares");
            partidas.push_back(juegosIndividuales);
        }
        else if(unPar(m1) == true && unPar(m2) == true)
        {
            vector<Carta> m1Vec, m2Vec;
            m1Vec.push_back(m1.c1());
            m1Vec.push_back(m1.c2());
            m1Vec.push_back(m1.c3());
            m1Vec.push_back(m1.c4());
            m1Vec.push_back(m1.c5());

            m2Vec.push_back(m2.c1());
            m2Vec.push_back(m2.c2());
            m2Vec.push_back(m2.c3());
            m2Vec.push_back(m2.c4());
            m2Vec.push_back(m2.c5());

            vector<Carta> cVerificadorasMano1(2), cVerificadorasMano2(2), cDesempateMano1(3), cDesempateMano2(3);
            for(vector<Carta>::reverse_iterator riter = m1Vec.rbegin(); riter != (m1Vec.rend() - 1); ++riter)
            {
                if((*riter).n() == (*(riter + 1)).n())
                {
                    cVerificadorasMano1.push_back(*riter);
                }
                else
                {
                    cDesempateMano1.push_back(*riter);
                }
            }
            for(vector<Carta>::reverse_iterator riter = m2Vec.rbegin(); riter != (m2Vec.rend() - 1); ++riter)
            {
                if((*riter).n() == (*(riter + 1)).n())
                {
                    cVerificadorasMano2.push_back(*riter);
                }
                else
                {
                    cDesempateMano2.push_back(*riter);
                }
            }
            if(cVerificadorasMano1.at(0).n() == cVerificadorasMano2.at(0).n())
            {
                vector<Carta>::iterator iterDM2 = cDesempateMano2.begin();
                for(vector<Carta>::iterator iterDM1 = cDesempateMano1.begin(); iterDM1 != cDesempateMano1.end(); ++iterDM1)
                {
                    if(*iterDM1 > *iterDM2)
                    {
                        juegosIndividuales = make_pair("Gana Jugador 1", "Por Par de igual valor con carta no pareada más alta");
                        partidas.push_back(juegosIndividuales);
                        break;
                    }
                    else if(*iterDM1 < *iterDM2)
                    {
                        juegosIndividuales = make_pair("Gana Jugador 2", "Por Par de igual valor con carta no pareada más alta");
                        partidas.push_back(juegosIndividuales);
                        break;
                    }
                    else if(iterDM1 == cDesempateMano1.end() - 1)
                    {
                        juegosIndividuales = make_pair("Empate", "Por Par de igual valor y cartas no pareadas de valores iguales");
                        partidas.push_back(juegosIndividuales);
                    }
                    ++iterDM2;
                }
            }
            else if(cVerificadorasMano1.at(0) > cVerificadorasMano2.at(0))
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "Por Par de mayor valor");
                partidas.push_back(juegosIndividuales);
            }
            else
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "Por Par de mayor valor");
                partidas.push_back(juegosIndividuales);
            }
        }
        else if(unPar(m1))
        {
            juegosIndividuales = make_pair("Gana Jugador 1", "Por tener Un Par");
            partidas.push_back(juegosIndividuales);
        }
        else if(unPar(m2))
        {
            juegosIndividuales = make_pair("Gana Jugador 2", "Por tener Un Par");
            partidas.push_back(juegosIndividuales);
        }
        else
        {
            if(m1.c5() > m2.c5())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "No tiene nada pero posee carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c5() < m2.c5())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "No tiene nada pero posee carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c4() > m2.c4())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "No tiene nada pero posee segunda carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c4() < m2.c4())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "No tiene nada pero posee segunda carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c3() > m2.c3())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "No tiene nada pero posee tercera carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c3() < m2.c3())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "No tiene nada pero posee tercera carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c2() > m2.c2())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "No tiene nada pero posee cuarta carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c2() < m2.c2())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "No tiene nada pero posee cuarta carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c1() > m2.c1())
            {
                juegosIndividuales = make_pair("Gana Jugador 1", "No tiene nada pero posee quinta carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else if(m1.c1() < m2.c1())
            {
                juegosIndividuales = make_pair("Gana Jugador 2", "No tiene nada pero posee quinta carta más alta");
                partidas.push_back(juegosIndividuales);
            }
            else
            {
                juegosIndividuales = make_pair("Empate", "Jugadores no tienen mano y poseen cartas del mismo valor");
                partidas.push_back(juegosIndividuales);
            }
        }
    }

    ofstream salida("PartidasDePoker.txt");

    string lineaParaArchivo(144, '-');

    salida << setw(92) << endl << "Ganadores de las mil partidas de Póker" << endl << endl;
    salida << lineaParaArchivo << endl << endl;

    salida << setw(23) << "Partida" << setw(21) << "Mano Jugador 1";
    salida << setw(18) << "Mano Jugador 2" << setw(14) << "Ganador" << setw(28) << "Motivo" << endl << endl;
    salida << lineaParaArchivo << endl << endl;
    int i = 1;
    unsigned int sangria = 23;
    entrada.seekg(0, entrada.beg);
    for(vector<pair<string, string> >::iterator iter = partidas.begin(); iter != partidas.end(); ++iter)
    {
        if(i == 10 || i == 100 || i == 1000)
        {
            --sangria;
        }
        entrada >> m1 >> m2;
        ordena(m1);
        ordena(m2);
        salida << setw(sangria) << "Partida " << i << ": " << setw(5) << m1 << setw(4) << m2;
        salida << "   " << (*iter).first << "    " << (*iter).second << endl;
        ++i;
    }
    entrada.close();
    salida.close();

    int contadorVictoriasJugador1 = 0, contadorVictoriasJugador2 = 0, contadorEmpates = 0;
    for(vector<pair<string, string> >::iterator iter = partidas.begin(); iter != partidas.end(); ++iter)
    {
        if((*iter).first == "Gana Jugador 1")
        {
            contadorVictoriasJugador1++;
        }
        else if((*iter).first == "Gana Jugador 2")
        {
            contadorVictoriasJugador2++;
        }
        else
        {
            contadorEmpates++;
        }
    }

    string linea(80, '-');

    cout << endl << setw(51) << "Resumen Juegos de Póker" << endl << endl;
    cout << linea << endl << endl;
    cout << setw(23) << contadorVictoriasJugador1 << " Partidas Ganadas por Jugador 1" << endl;
    cout << setw(23) << contadorVictoriasJugador2 << " Partidas Ganadas por Jugador 2" << endl;
    cout << setw(23) << contadorEmpates << " Partidas Empatadas" << endl << endl;
    cout << linea << endl << endl;

    cout << "En el archivo 'PartidasDePoker.txt' se muestran los resultados de las mil parti-das de Póker." << endl;

    return 0;
}
