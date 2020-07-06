<https://de.wikipedia.org/wiki/Shunting-yard-Algorithmus>

Algorithmus für Kovertierung Infixnotation zu Postfixnotation:

-   Stack mit LIFO-Prinzip und Ausgabe-Queue anlegen.

-   SOLANGE Tokens verfügbar sind:

    -   Token einlesen.

    -   WENN Token IST-Zahl:

        -   Token ZU Ausgabe.

    -   ENDEWENN

    -   WENN Token IST-Operator

        -   SOLANGE Stack IST-NICHT-LEER UND Stack-Spitze IST Operator
            UND Präzedenz von Token IST-KLEINER Präzedenz von
            Stack-Spitze:

            -   Stack-Spitze ZU Ausgabe.

        -   ENDESOLANGE

        -   Token ZU Stack.

    -   ENDEWENN

    -   WENN Token IST öffnende-Klammer:

        -   Token ZU Stack.

    -   ENDEWENN

    -   WENN Token IST schließende-Klammer:

        -   BIS Stack-Spitze IST öffnende-Klammer:

            -   FEHLER-BEI Stack IST-LEER:

                -   GRUND (1) Der schließenden Klammer geht keine
                    öffnende voraus.

            -   ENDEFEHLER

            -   Stack-Spitze ZU Ausgabe.

        -   ENDEBIS

        -   Stack-Spitze (öffnende-Klammer) entfernen

    -   ENDEWENN

-   ENDESOLANGE

-   BIS Stack IST-NICHT-LEER:

    -   FEHLER-BEI Stack-Spitze IST öffnende-Klammer:

        -   GRUND (1) Es gibt mehr öffnende als schließende Klammern.

    -   ENDEFEHLER

    -   Stack-Spitze ZU Ausgabe.

-   ENDEBIS

    -   -   
