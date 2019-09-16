void affiche_tab(double t[], int n);
double init (double t[], int n);

void affiche_tab(double t[], int n){
	int i;
	for(i=0;i<n;++i){
		printf("%f\n",t[i]);
	}
}

double init (double t[], int n){
	for(i=0;i<n;++i){
		t[i]=0.;
	}
}


