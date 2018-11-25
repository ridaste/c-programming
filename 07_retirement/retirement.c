#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calculate_monthly_balance (double balance, double rate, double input) {
  balance += balance * rate + input;
  return balance;
}

double print_monthly_status (double balance, int startAge, int number_months, double rate, double contribution) {

  int age_in_years = startAge / 12;
  int year_months = startAge % 12;

  for (int i = 0; i < number_months; i++) {
    age_in_years = (startAge + i) / 12;
    year_months = (startAge + i) % 12;
    printf("Age %3d month %2d you have $%.2lf\n", age_in_years, year_months, balance);
    balance = calculate_monthly_balance(balance, rate, contribution);
  }

  return balance;

}

void retirement (int startAge, double initial, retire_info w, retire_info r) {

  double balance = initial;

  balance = print_monthly_status(balance, startAge, w.months, w.rate_of_return, w.contribution);

  startAge += w.months;

  balance = print_monthly_status(balance, startAge, r.months, r.rate_of_return, r.contribution);

}

int main () {

  double startingAge = 327;
  double initial_balance = 21345;

  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(startingAge, initial_balance, working, retired);
  return EXIT_SUCCESS;
}
