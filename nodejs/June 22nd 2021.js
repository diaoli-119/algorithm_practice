/*
 * @Author: your name
 * @Date: 2021-06-21 11:59:09
 * @LastEditTime: 2021-06-22 09:50:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \codility\app.js
 */

//check a binary string, e.g. '00011110111', converts it to a decimal. if the decimal is odd, substracted by 1, if even, divided by 2,
//until it is equal to 0.
//give the times of the calculation
function calTimes(N){    
    let dec = parseInt(N,2);
    let val = 0;
    while(dec > 1)
    {
        if(dec%2 === 0){
            dec /= 2;
            ++val;
        }
        else if(dec%2 === 1){
            dec -= 1;
            ++val;
            dec /= 2;
            ++val;
        }
    }
    dec--;
    return ++val;

}

//check the status of an array. Multiple all the elements in the array, if the result < 0, return -1; = 0, return 0; > 0, return 1
function checkStatus(A){
    let len = A.length;
    let ret = A[0];
    for(i = 1; i < len; i++)
    {
        ret *= A[i];
    }
    if(ret < 0) return -1;
    else if(ret === 0) return 0;
    else return 1;
}

//return a day between 'Mon' and 'Sun'
function aDay(S,K){
    let day = {
        "Mon":0,
        "Tue":1,
        "Wed":2,
        "Thu":3,
        "Fri":4,
        "Sat":5,
        "Sun":6
    }
    let ret = (K%7 + day[S])%7;
    switch(ret)
    {
        case 0: return "Mon";
        case 1: return "Tue";
        case 2: return "Wed";
        case 3: return "Thu";
        case 4: return "Fri";
        case 5: return "Sat";
        case 6: return "Sun";
        default: return "Error";
    }
}

// given a number 'n', return an array which has n elements. The sum of these elements is equal to 0
function sum2Zero(n) {
    let res = [];
    for (let i = 1; i <= (Math.random() * n); i++) {
        res.push(i, -i);
    }
    return res;
}

const main = () => {
    console.log(func4(4));
}

main();