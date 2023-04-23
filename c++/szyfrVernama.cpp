#include iostream
#include string
#include vector
#include random
#include ctime
using namespace std;
                            
// funkcja kodująca wiadomość przy użyciu klucza
string szyfrujVernama(string wiadomosc, string klucz) {
    string szyfrogram = "";
    for (int i = 0; i < wiadomosc.length(); i++) {

        char c = wiadomosc[i] ^ klucz[i];
        szyfrogram += c;
        }
        return szyfrogram;
    }
                        
// funkcja generująca losowy klucz o podanej długości
string generujKlucz(int dlugosc) {
    string klucz = "";
    // generator liczb losowych
    default_random_engine generator(time(0));
    uniform_int_distribution(int) distribution(0, 255);
    for (int i = 0; i < dlugosc; i++) {
        // generowanie kolejnego bajtu klucza
        int bajt = distribution(generator);
        klucz += (char)bajt;
    }
    return klucz;
}

int main() {
    string wiadomosc = "Tajna wiadomość";
    string klucz = generujKlucz(wiadomosc.length()); 
    cout << "Wiadomość: " << wiadomosc << endl;
    cout << "Klucz: " << klucz << endl;
    string szyfrogram = szyfrujVernama(wiadomosc, klucz); 
    cout << "Zaszyfrowana wiadomość: " << szyfrogram << endl;
    string odszyfrowanaWiadomosc = szyfrujVernama(szyfrogram, klucz);
    cout << "Odszyfrowana wiadomość: " << odszyfrowanaWiadomosc << endl;
    return 0;
}
    