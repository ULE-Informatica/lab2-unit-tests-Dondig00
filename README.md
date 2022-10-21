# dps-laboratory2

Para hacer funcionar los test correctamente se han realizado los siguientes pasos
usando una VM de windows con ubuntu 22.04.


1º Instalamos las dependencias necesarias

    sudo apt install cmake
    sudo apt-get install libgtest-dev
    sudo apt-get install build-essential

2º Creamos las librerias de Gtest para el equipo 

    cd /usr/src/gtest
    sudo cmake CMakeLists.txt
    sudo make
    cd lib/
    sudo cp *.a /usr/lib

3º Compilamos y corregimos fallo en link.txt
    cd /*REPOS*/
    mkdir build 
    cd build
    sudo cmake ..
    cd ~/CMakeFiles/runTest.dir
    sudo vi link.txt // sustituimos -lThreads::Threads -> -pthread
    cd /*REPOS*/

4º Volvemos al build y ejecutamos

    cd /*build*/
    sudo make
    ./runTests



Ahora ya tenemos los Test ejecutados que de salida han dado los siguientes valores 

    [==========] Running 6 tests from 3 test suites.
    [----------] Global test environment set-up.
    [----------] 2 tests from wrapAddFunctionTest
    [ RUN      ] wrapAddFunctionTest.NonWrappingNums
    [       OK ] wrapAddFunctionTest.NonWrappingNums (0 ms)
    [ RUN      ] wrapAddFunctionTest.WrappingNums
    [       OK ] wrapAddFunctionTest.WrappingNums (0 ms)
    [----------] 2 tests from wrapAddFunctionTest (0 ms total)

    [----------] 2 tests from wrapMulFunctionTest
    [ RUN      ] wrapMulFunctionTest.NonWrappingMulNums
    [       OK ] wrapMulFunctionTest.NonWrappingMulNums (0 ms)
    [ RUN      ] wrapMulFunctionTest.WrappingMulNums
    [       OK ] wrapMulFunctionTest.WrappingMulNums (0 ms)
    [----------] 2 tests from wrapMulFunctionTest (0 ms total)

    [----------] 2 tests from wrapShiftFunctionTest
    [ RUN      ] wrapShiftFunctionTest.NonWrappingMulBNums
    [       OK ] wrapShiftFunctionTest.NonWrappingMulBNums (0 ms)
    [ RUN      ] wrapShiftFunctionTest.WrappingMulBNums
    [       OK ] wrapShiftFunctionTest.WrappingMulBNums (0 ms)
    [----------] 2 tests from wrapShiftFunctionTest (0 ms total)

    [----------] Global test environment tear-down
    [==========] 6 tests from 3 test suites ran. (0 ms total)
    [  PASSED  ] 6 tests.

Sin embargo estos tests no estan bien porque permiten wrapping asi que los modificamos tanto el codigo del programa como el de test 
Y nos proporciona el siguiente resultado

    [==========] Running 6 tests from 3 test suites.
    [----------] Global test environment set-up.
    [----------] 2 tests from wrapAddFunctionTest
    [ RUN      ] wrapAddFunctionTest.NonWrappingNums
    [       OK ] wrapAddFunctionTest.NonWrappingNums (0 ms)
    [ RUN      ] wrapAddFunctionTest.WrappingNums
    Unsigned wrap aborted addition operation
    [       OK ] wrapAddFunctionTest.WrappingNums (0 ms)
    [----------] 2 tests from wrapAddFunctionTest (0 ms total)

    [----------] 2 tests from wrapMulFunctionTest
    [ RUN      ] wrapMulFunctionTest.NonWrappingMulNums
    [       OK ] wrapMulFunctionTest.NonWrappingMulNums (0 ms)
    [ RUN      ] wrapMulFunctionTest.WrappingMulNums
    Unsigned wrap aborted multiplication operation
    [       OK ] wrapMulFunctionTest.WrappingMulNums (0 ms)
    [----------] 2 tests from wrapMulFunctionTest (0 ms total)

    [----------] 2 tests from wrapShiftFunctionTest
    [ RUN      ] wrapShiftFunctionTest.NonWrappingMulBNums
    [       OK ] wrapShiftFunctionTest.NonWrappingMulBNums (0 ms)
    [ RUN      ] wrapShiftFunctionTest.WrappingMulBNums
    Unsigned wrap aborted during shift operation
    [       OK ] wrapShiftFunctionTest.WrappingMulBNums (0 ms)
    [----------] 2 tests from wrapShiftFunctionTest (0 ms total)

    [----------] Global test environment tear-down
    [==========] 6 tests from 3 test suites ran. (0 ms total)
    [  PASSED  ] 6 tests.


Las modificaciones al código se han en base al criterio de reglas Int30-C e Int34-C las cuales pueden ser encontradas en su confluence:

https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=87152052