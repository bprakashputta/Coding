import java.util.Queue;
import java.util.LinkedList;

// Java program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes

class SieveOfEratosthenes
{
    public Queue<Integer> numbers = new LinkedList<Integer>();
    public Queue<Integer> primes = new LinkedList<Integer>();

    SieveOfEratosthenes(int n){
        for(int i=2; i<=n; i++){
            numbers.add(i);
        }
    }

    // Sieve using Array
	// void sieveOfEratosthenes(int n)
	// {
	// 	// Create a boolean array "prime[0..n]" and initialize
	// 	// all entries it as true. A value in prime[i] will
	// 	// finally be false if i is Not a prime, else true.
	// 	boolean prime[] = new boolean[n+1];
	// 	for(int i=0;i<=n;i++)
	// 		prime[i] = true;
		
	// 	for(int p = 2; p*p <=n; p++)
	// 	{
	// 		// If prime[p] is not changed, then it is a prime
	// 		if(prime[p] == true)
	// 		{
	// 			// Update all multiples of p
	// 			for(int i = p*p; i <= n; i += p)
	// 				prime[i] = false;
	// 		}
	// 	}
		
	// 	// Print all prime numbers
	// 	for(int i = 2; i <= n; i++)
	// 	{
	// 		if(prime[i] == true)
	// 			System.out.print(i + " ");
	// 	}
	// }
	
    public Queue<Integer> getPrimeNumbers(Queue<Integer> nums){
        Queue<Integer> temp = new LinkedList<Integer>();
        Queue<Integer> primeNums = new LinkedList<Integer>();
        while(!numbers.isEmpty()){
            int p = numbers.remove();
            // System.out.println("p:"+p);            
            while(!numbers.isEmpty()){
                int num = numbers.remove();
                // System.out.print(num+" ");
                if(num%p!=0){
                    temp.add(num);
                }
            }
            primeNums.add(p);
            while(!temp.isEmpty()){
                int num = temp.remove();
                numbers.add(num);
            }
            // System.out.println();
        }
        return primeNums;
    } 


    public static void printAllPrimeNumbersUptoN(Queue<Integer> primeNums){
        if(primeNums.isEmpty()){
            return;
        }else{
            int ele = primeNums.remove();
            System.out.print(ele+" ");
            printAllPrimeNumbersUptoN(primeNums);
        }
    }
	public static void main(String args[])
	{
		int n = 1000;
		System.out.print("Following are the prime numbers ");
		System.out.println("smaller than or equal to " + n);
		SieveOfEratosthenes g = new SieveOfEratosthenes(n);
		Queue<Integer> primeNums = g.getPrimeNumbers(g.numbers);
        printAllPrimeNumbersUptoN(primeNums);
	}
}
