#include <stdio.h>
#include <math.h>

int main(){
    int n,l;
    scanf(" %d", &n);
    
    for(l=0;l<n;l++){
        
    	int c;
    	int h;
    	int o;
    	
    	scanf(" %d %d %d", &c, &h, &o);
    
        int tam, minfin, i=0;
    
    	int nc;
    	int nh;
    	int no;
    	
    	int a;
        int d;
    	int g;
    	
    	for (d=0;d<=c||d<=(o/2);d++)
    		for (g=0;g<=(c/6)||g<=(h/12)||g<=(o/6);g++)
    			for (a=0;a<=o||a<=(h/2);a++)
    			    i++;
    	
    	tam = i;
    	
    	int min[tam];
    
    	i=0;
    
    	for (d=0;d<=c||d<=(o/2);d++){
    		for (g=0;g<=(c/6)||g<=(h/12)||g<=(o/6);g++){
    			for (a=0;a<=o||a<=(h/2);a++){
    				nc = c - d - 6*g;
    				nh = h - 2*a - 12*g;
    				no = o - 2*d - a - 6*g;
    			    min[i]= abs(nc) + abs(no) + abs(nh);
    			    i++;
    			}
    		}
    	}
    	nc = i;
    	minfin = min[0];
    	
    	for(i=0;i<tam;i++){
    	    if(min[i] < minfin)
    	        minfin = min[i];
    	}
    
    	printf("%d\n", minfin);
    		
    }
}