#include <stdio.h>

//SLE = assetvalue * exposure factor
//ALE = SLE * ARO
//CBA = ALE(prior)-ALE(post)-ACS

double SLE(double AV, double EF);
double ALE(double SLEET, double freqpyear);

int main(void)
{
	double likely, CBA, ASP, EF, AV, PL, uncertain, lossfreq, lossmag, risk, percentrisk, lossmag1, lossfreq1;
	printf("Enter the Exposure Factor of an attack in decimal form:	");
	scanf("%lf", &likely);
	printf("Enter the rate of occurrence of an attack in decimal form:  ");
	scanf("%lf", &ASP);
	printf("Enter the Asset Value of the asset in question in decimal form:	");
	scanf("%lf", &AV);
	printf("Enter the Annual Cost of Safeguard in decimal form:  ");
	scanf("%lf", &PL);
	//printf("Enter the uncertainty of all inputted data in decimal form:	");
	//scanf("%lf", &uncertain);
	
	lossfreq = SLE(AV, likely);
	lossmag = ALE(lossfreq, ASP );
	printf("ALE is %.2lf\n", lossmag);
	printf("Enter the new Exposure Factor:	");
	scanf("%lf", &EF);
	lossfreq1 = SLE(AV, EF);
	lossmag1 = ALE(lossfreq1, ASP);  
	CBA = lossmag - lossmag1 - PL;
	//percentrisk = risk x 100;
	printf("$%.2lf is the cost benefit analysis", CBA);
	if (CBA <= 0)
	{
		printf("It is not worth it. Stick to what we have.");	
	}
	else
	{
		printf("This should be implemented as soon as possible.");
	}
	
	

}

double SLE(double AV, double EF)
{
	return AV * EF; 
}

double ALE(double SLEET, double freqpyear)
{
	return SLEET * freqpyear;
}