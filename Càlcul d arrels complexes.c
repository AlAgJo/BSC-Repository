/*per calcular les arrels aplicarem Newton-Raphson als valors de z al
quadrat [-3,3]x[-3,3] de C*/
/*per fer-ho veurem si convergeix el N-R. Això ho farem per tot z mencionat
abans aplicant el mètode en forma de graella de dreta a esquerra i de dalt
a baix*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define h 1e-2 /*separació entre valors de la successió*/
#define tol 1e-2 /*l ímit en que denominador és massa pròxim a 0*/
#define prec 1e-10 /*precisió de convergència*/
#define iter 12 /*nombre màxim d'iterats*/

/*defineixo l'estructura per treballar en complexos*/
typedef struct{
	double real;
	double imag;
} comp;

/*inicio les funcions operació en complexos*/
comp suma(comp a, comp b);
comp resta(comp a, comp b);
comp prod(comp a, comp b);
comp divi(comp a, comp b);

/*inicio les altres funcions*/
comp f1(comp z);
comp derivpol(comp (*f)(comp), comp z, comp preccomp);

int main() {

    FILE *pf = NULL;
    int i;
    double *xi;
    double *yi;
    comp aux, prov;
    /*definim les arrels*/
    comp a1, a2, a3;
    a1.real = 1;
    a1.imag = 0;
    a2.real = 2;
    a2.imag = 1;
    a3.real = 0;
    a3.imag = 2;
    /*defineixo variable z*/
    comp zi;
    zi.real = -3;
    zi.imag = 3;
    /*assigno xi i yi a zi*/
    xi = &zi.real;
    yi = &zi.imag;
    /*defineixo presició complexa*/
    comp preccomp;
    preccomp.real = prec;
    preccomp.imag = 0;
    /*em moc per les components reals des de 3 fins a -3 i 
    per les components imaginàries des de -3i fins a 3i*/
    while((*xi) <= 3){
        while((*yi) >= -3){
            /*apliquem newton raphson*/
            for(i = 0; i < iter; i++){
                /*comprovem que no explota*/
                prov = derivpol(f1, zi, preccomp);
                if(fabs(prov.real) <= tol && fabs(prov.imag) <= tol){
                    pf = fopen(53.res0, "w");
                    if(pf == NULL){
                        printf("error en obrir el fitxer\n");
                        exit(1);
                    }
                    fprintf(pf, "%2.3f %2.3f ", aux.real, aux.imag);
                    fclose(pf);
                    break;
                }
                aux = zi;
                zi = resta(zi, divi(f1(zi), derivpol(f1, zi, preccomp)));
                /*comprovem que convergeix*/
                /*convergeix a l'arrel a1*/
                prov = resta(zi, a1);
                else if(fabs(prov.real) <= prec && fabs(prov.imag) <= prec){
                    pf = fopen(53.res1, "w");
                    if(pf == NULL){
                        printf("error en obrir el fitxer\n");
                        exit(1);
                    }
                    fprintf(pf, "%2.3f %2.3f ", aux.real, aux.imag);
                    fclose(pf);
                    break;
                }
                /*convergeix a l'arrel a2*/
                prov = resta(zi, a2);
                else if(fabs(prov.real) <= prec && fabs(prov.imag) <= prec){
                    pf = fopen(53.res2, "w");
                    if(pf == NULL){
                        printf("error en obrir el fitxer\n");
                        exit(1);
                    }
                    fprintf(pf, "%2.3f %2.3f ", aux.real, aux.imag);
                    fclose(pf);
                    break;
                }
                /*convergeix a l'arrel a3*/
                prov = resta(zi, a3);
                else if(fabs(prov.real) <= prec && fabs(prov.imag) <= prec){
                    pf = fopen(53.res3, "w");
                    if(pf == NULL){
                        printf("error en obrir el fitxer\n");
                        exit(1);
                    }
                    fprintf(pf, "%2.3f %2.3f ", aux.real, aux.imag);
                    fclose(pf);
                    break;
                }
                /*no convergeix*/
                else{
                    pf = fopen(53.res4, "w");
                    if(pf == NULL){
                        printf("error en obrir el fitxer\n");
                        exit(1);
                    }
                    fprintf(pf, "%2.3f %2.3f ", aux.real, aux.imag);
                    fclose(pf);
                    break;
                }
            }
            /*augmentem un pas imaginari*/
            *yi -= h; 
        }
        /*augmentem un pas real*/
        *xi += h;   
    }
    return 0;
}

comp suma(comp a, comp b){
	comp c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}


/*defineixo les funcions operació en complexos*/
comp resta(comp a, comp b){
	comp c;
	c.real = a.real - b.real;
	c.imag = a.imag - b.imag;
	return c;
}

comp prod(comp a, comp b){
	comp c;
	c.real = (a.real * b.real) - (a.imag * b.imag);
	c.imag = (a.real * b.imag) + (a.imag * b.real);
	return c;
}

comp divi(comp a, comp b){
	comp c;
	c.real = c.imag = 0;
	if(b.real == 0 && b.imag == 0){
		printf("No podem dividir per b ja que és 0\n");	
        return c;
    }
	else{
		c.real = (double)((a.real * b.real) + (a.imag * b.imag)) / ((b.real * b.real) + (b.imag * b.imag));
		c.imag = (double)((a.imag * b.real) - (a.real * b.imag)) / ((b.real * b.real) + (b.imag * b.imag));
		return c;	
	}
}

/*defineixo les altres funcions*/
/*defineixo les funcions que analitzarem*/
comp f1(comp z){
    /*definim les arrels*/
    comp a1, a2, a3;
    a1.real = 1;
    a1.imag = 0;
    a2.real = 2;
    a2.imag = 1;
    a3.real = 0;
    a3.imag = 2;
    return prod(prod((resta(z, a1)), (resta(z, a2))), (resta(z, a3)));
}
/*derivada d'un polinomi*/
comp derivpol(comp (*f)(comp), comp z, comp preccomp){
    comp dos;
    dos.real = 2;
    dos.imag = 0;
    return divi(resta((*f)(suma(z, preccomp)), (*f)(resta(z, preccomp))), prod(dos, preccomp));
}
