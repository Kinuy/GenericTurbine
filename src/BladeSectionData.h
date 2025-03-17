#pragma once

class BladeSectionData {
public:
	BladeSectionData();
	~BladeSectionData();

	double	cl;
	double	cd;
	double	cn;
	double	a;
	double	ac;
	double	alpha;
	double	alphaInflow;
	double	prandtlTiplossFactor;
	double	glauertThrustFactor;
	double	reynoldsNumber;
	double	cp;
	double	cm;
	double	ct;
	double	tsr;
	double	inflowVelocity;
private:

};
