/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"



int main(void)
{
    startTesting(1); // al_newArrayList       lista al 100%
    startTesting(2); // al_add              lista al 100%
    startTesting(3); // al_deleteArrayList lista al 100%
    startTesting(4); // al_len               lista al 100%
    startTesting(5); // al_get             lista al 100%
    startTesting(6); // al_contains        lista al 100%
    startTesting(7); // al_set             lista al 100%,tengo q preguntar al profe
    startTesting(8); // al_remove            lista al 100%,tengo q preguntar al profe
    startTesting(9); // al_clear           lista al 100%,tengo q preguntar al profe
    startTesting(10); // al_clone           lista al 100%,  tengo q preguntar al profe
    startTesting(11); // al_push            lista al 100%,  tengo q preguntar al profe
    startTesting(12); // al_indexOf          lista al 100%, tengo q preguntar al profe
    startTesting(13); // al_isEmpty            lista al 100%, tengo q preguntar al profe
    startTesting(14); // al_pop               lista al 100%, tengo q preguntar al profe
    startTesting(15); // al_subList           lista al 100%,  tengo q preguntar al profe
    startTesting(16); // al_containsAll        lista al 100%, tengo q preguntar al profe
    startTesting(17); // al_sort

    return 0;
}





