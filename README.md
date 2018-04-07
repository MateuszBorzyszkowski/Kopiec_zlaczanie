# Kopiec_zlaczanie
##Projekt akademicki z AiSD.


Zaimplementuj (samodzielnie) kopiec maksymalizujący i następujące operacje na nim:

- '+' nr v
    dodanie do kopca o numerze nr liczby v


- '-' nr
    usunięcie z kopca o numerze nr maksimum i wypisanie go na ekran

- p nr
    wypisanie wszystkich elementów z kopca w kolejności, w jakiej znajdują się w tablicy

- r nr n v1 ...vn
    usunięcie z kopca o numerze nr wszystkich elementów i wpisanie do niego n nowych, o wartościach v1 ...vn

- j a b
    złączenie kopców a i b; w wyniku kopiec a powinien zawierać wszystkie elementy z obu kopców, kopiec b powinien być pusty;
    po operacji j k k kopiec k powinien być pusty (najpierw łączymy k z k, potem czyścimy k)

- q
    zakończenie programu

Numerami kopców będą liczby 0, 1, ..., 9. Rozmiar żadnego kopca nie przekroczy 8192 elementów. Na wejściu pojawi się ciąg poleceń w przedstawionym wyżej formacie. Ostatnim poleceniem będzie polecenie q. Na wyjściu należy wypisać wynik poleceń - i p.
