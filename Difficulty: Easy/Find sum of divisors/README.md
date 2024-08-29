<h2><a href="https://www.geeksforgeeks.org/problems/find-sum-of-divisors5636/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Find sum of divisors</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a natural number <strong>N</strong>, the task is to find the sum of the divisors of all the divisors of N.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 54
<strong>Output:
</strong>232
<strong>Explanation:
</strong>Divisors of 54 = 1, 2, 3, 6, 9, 18, 27, 54.
Sum of divisors of 1, 2, 3, 6, 9, 18, 27, 54 
are 1, 3, 4, 12, 13, 39, 40, 120 respectively.
Sum of divisors of all the divisors of 54
 = 1 + 3 + 4 + 12 + 13 + 39 + 40 + 120 = 232.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 10
<strong>Output:
</strong>28
<strong>Explanation:
</strong>Divisors of 10 are 1, 2, 5, 10
Sums of divisors of all the divisors are 
1, 3, 6, 18.
Overall sum = 1 + 3 + 6 + 18 = 28</span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong></span><br>
<span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>sumOfDivisors()</strong>&nbsp;which takes an integer N as an input parameter and return&nbsp;the&nbsp;sum of the divisors of all the divisors of N.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(NloglogN)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N&nbsp;&lt;= 10<sup>4</sup></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;<code>Prime Number</code>&nbsp;<code>Algorithms</code>&nbsp;