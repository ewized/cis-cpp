/*
	File: bodyweight.cpp
	Problem: #14 Pg 245
	Description: To maintain one's body weight, an adult human needs to
		consume enough calories daily to (1) meet the basal metabolic rate
		(engery required to breath, maintain body temperture, etc), (2)
		account for physical activiy such as execise, and (3) account for the
		engery required to digest the food that is being eaten. For an adult
		that weighs P pounds, we can estmate these caloric requirements using
		the following forumuls.

		1. Basal metabolic rate: Calo required = 70 * (P/2.2)^0.756
		2. Physical activity: Calo required = 0.0385 * Intensity * P * Minutes
		3. Engery to digest food: Calo required = TotalCaloriesConsumed * 0.1

		Write a function that computes the calories required for the basal
		metabolic rate, taking as input parametes for the intensity, weight,
		and minuets spent exercising.

		Use these functions in a program that inputs a persone's weight, an
		estimate for the intensity of physical activity, the number of
		minutes spent performing the physical activity, and  the number of
		calories in one serving of your favorite food. The program should
		then calculate and output how many servings of that food should be
		eaten per day to maintain  the person's current weight at the 
		activy level. The computation should include the engery that is
		required to digest food.
	Name: Joshua Rodriguez
	Email: ewized@gmail.com
	Date: 9/21/2013
*/
#include <iostream>
#include <cmath>

using namespace std;

// Declaring the functions in the stack.
double getUserWeight();
double getWorkoutIntensity();
double getWorkoutTime();
double getCaloriesFood();
double getBasalMetabolicRate(double);
double getPhysicalActivity(double, double, double);
double getDigestFood(double);
double getServingSize(double, double, double, double);

// System main function.
int main()
{
	double userWeight, workoutIntensity, workoutTime, caloriesFood, 
		basalMetabolicRate, physicalActivity, digestFood;

	userWeight = getUserWeight();
	workoutIntensity = getWorkoutIntensity();
	workoutTime = getWorkoutTime();
	caloriesFood = getCaloriesFood();

	cout << "The caloires required for your basal metabolic rate is: " 
		 << getBasalMetabolicRate(userWeight) << endl
		 << "The calories required for physical activiy is: "
		 << getPhysicalActivity(workoutIntensity, userWeight, workoutTime)
		 << endl
		 << "The calories required to digest your food is: "
		 << getDigestFood(caloriesFood) << endl
		 << "The servings you need to eat per day is: ";
	cout << getServingSize(userWeight, workoutIntensity, workoutTime, caloriesFood)
		 << endl;

	return 0;
}

// getUserWeight and return that users weight.
double getUserWeight()
{
	double weight;
	cout << "Enter your weight: ";
	cin >> weight;
	return weight;
}

// getWorkoutIntensity and return that intensity.
double getWorkoutIntensity()
{
	double intensity;
	cout << "Enter the workout intensity: ";
	cin >> intensity;
	return intensity;
}

// getWorkoutTime and return that time in minutes.
double getWorkoutTime()
{
	double minutes;
	cout << "Enter the minutes you worked: ";
	cin >> minutes;
	return minutes;
}

// getCaloriesFood and return that calories.
double getCaloriesFood()
{
	double calories;
	cout << "Enter the calories of your favorite food: ";
	cin >> calories;
	return calories;
}

// getBasalMetabolicRate and return it.
double getBasalMetabolicRate(double weight)
{
	double stepOne = pow((weight/2.2),0.756);
	return 70 * stepOne;
}

// getPhysicalActivity and return it.
double getPhysicalActivity(double intensity, double weight, double time)
{
	return 0.0385 * intensity * weight * time;
}

// getDigestFood and return the engery that is used.
double getDigestFood(double calories)
{
	return calories * 0.1;
}

// getServingSize per day to maintain current weight for their activity level.
double getServingSize(double weight, double activity, double time, double calories)
{	
	double size;
	size = getPhysicalActivity(activity, weight, time);
	size = size + getDigestFood(calories);
	size = size + getBasalMetabolicRate(weight);
	return size/calories;
}
