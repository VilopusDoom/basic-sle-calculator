#include <stdio.h>

//Risk Management Calculation Program

double LossFreq(double likely, double ASP);
double LossMag(double AssetVal, double ProbLoss);

int main(void)
{
	double likely, ASP, AV, PL, uncertain, lossfreq, lossmag, risk, percentrisk;
	printf("Enter the likelihood of an attack in decimal form:	");
	scanf("%lf", &likely);
	printf("Enter the probability of success of an attack in decimal form:	");
	scanf("%lf", &ASP);
	printf("Enter the Asset Value of the asset in question in decimal form:	");
	scanf("%lf", &AV);
	printf("Enter the Probability Loss should an attack be successful in decimal form:	");
	scanf("%lf", &PL);
	printf("Enter the uncertainty of all inputted data in decimal form:	");
	scanf("%lf", &uncertain);
	
	lossfreq = LossFreq(likely, ASP);
	lossmag = LossMag(AV, PL);
	risk = (lossfreq * lossmag) + ((lossfreq * lossmag)*0.1);
	percentrisk = risk x 100;
	printf("The risk is %lf, or %lf percent.", risk, percentrisk);
	
	
	

}

double LossFreq(double likely, double ASP)
{
	return likely * ASP; 
}

double LossMag(double AssetVal, double ProbLoss)
{
	return AssetVal * ProbLoss;
}