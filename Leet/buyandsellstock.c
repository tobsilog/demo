// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

#include <stdio.h>

int main(){
    int i, days, min = 0, buy, sell, max = 0; 
    
    printf("Enter days for stock: ");
    scanf("%d", &days);

    int prices[days];

    for(i = 0; i < days; i++){
        printf("Enter price on day %d: ", i + 1);
        scanf("%d", &prices[i]);
        min = (i == 0) ? prices[i] : min;
        if(prices[i] < min){
            min = prices[i];
            buy = i + 1;
            max = 0;
        }
        if(prices[i] > max){
            max = prices[i];
            sell = i + 1;
        }
    }

    int sum = max - min;
    if(sell < buy){
        printf("Max Profit: 0");
    } else {
        printf("Buy on day %d and sell on day %d", buy, sell);

        printf("\nMax Profit: %d", sum);

    }

}