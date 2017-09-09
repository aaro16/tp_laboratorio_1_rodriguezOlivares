#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float cargaFloat();
void sumaFuncion(float a,float b);
void restaFuncion(float a,float b);
void divisionFuncion(float a,float b);
void multiplicacionFuncion(float a,float b);
void factorialFuncion(float a, float b);
void todasFunciones(float a,float b);

float cargaFloat()
{
    float x;
    printf("Ingrese Operando \n");
    scanf("%f",&x);

    return x;
}

void sumaFuncion(float a,float b)
{
    float x;
    x=a+b;

    printf("Resultado Suma= %.2f \n",x);

}

void restaFuncion(float a,float b)
{
    float x;
    x=a-(-b);

    printf("Resultado Resta= %.2f \n",x);

}

void divisionFuncion(float a,float b)
{

    float x;
    x=a/b;

    if(b!=0)
    {
            printf("Resultado Division= %.3f \n",x);
    }

    else
    {
        printf("Resultado Division= ERROR, divisor 0 \n");
    }
}
void multiplicacionFuncion(float a,float b)
{
    float x;
    x=a*b;

    printf("Resultado Multiplicacion= %.2f \n",x);

}

void factorialFuncion(float a, float b)
{
    float factorialA;
    float factorialB;
    int i;

    factorialA=a;
    factorialB=b;

    if(a>0 && a<13)
    {
        for(i=1;i<a;i++)
        {
            factorialA=factorialA*(a-i);
        }

        printf("Factorial A= %.f \n",factorialA);
    }

    else if(a==0)
    {
            printf("Factorial A= 1\n");
    }

    else
    {
        printf("Factorial A= ERROR, el numero debe ser positivo, entero y menor a 13 \n");
    }

    if(b>0 && b<13)
    {
        for(i=1;i<b;i++)
        {
            factorialB=factorialB*(b-i);
        }

         printf("Factorial B= %.f \n",factorialB);
    }

    else if(b==0)
    {
            printf("Factorial B= 1\n");
    }

    else
    {
        printf("Factorial B= ERROR, el numero debe ser positivo, entero y menor a 13 \n");
    }
}

void todasFunciones(float a,float b)
{
                sumaFuncion(a,b);
                restaFuncion(a,b);
                divisionFuncion(a,b);
                multiplicacionFuncion(a,b);
                factorialFuncion(a,b);
}

#endif // FUNCIONES_H_INCLUDED
