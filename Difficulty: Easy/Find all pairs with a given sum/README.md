<h2><a href="https://www.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1?page=1&sprint=a663236c31453b969852f9ea22507634&sortBy=submissions">Find all pairs with a given sum</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two unsorted arrays <strong>a[]</strong> &nbsp;and b<strong>[]</strong>, the task is to find all pairs whose sum equals <strong>x</strong> from both arrays.</span></p>
<p><span style="font-size: 18px;">Note:<strong>&nbsp;</strong>All pairs should be returned in <strong>increasing </strong>order of u. For eg. for two pairs (u<sub>1</sub>,v<sub>1</sub>) and (u<sub>2</sub>,v<sub>2</sub>), if u<sub>1&nbsp;</sub>&lt; u<sub>2</sub> then (u<sub>1</sub>,v<sub>1</sub>) should be returned first else second.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>target = 9, a[] = [1, 2, 4, 5, 7], b[] = [5, 6, 3, 4, 8]
<strong>Output: <br></strong>1 8
4 5 
5 4
<strong>Explanation: </strong>(1, 8), (4, 5), (5, 4) are the pairs which sum to 9.</span>
</pre>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">target = 8, a[] = [-1, -2, 4, -6, 5, 7], b[] = [6, 3, 4, 0]
</span><strong style="font-size: 18px;">Output:</strong><span style="font-size: 18px;">
4 4 
5 3<br></span></span></pre>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input</strong><span style="font-size: 18px;">: target = 9, a[] = [1, 2, 4, 5, 7, 4], b[] = [5, 6, 3, 4, 8, 4]<br><strong>Output</strong>:<br>1 8<br>4 5<br>4 5<br>5 4<br>5 4
<strong>Explanation</strong>: (1, 8), (4, 5), (4, 5), (5, 4) and (5, 4) are the pairs which sum to 9.</span></span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr1.size, arr2.size ≤ 10<sup>5</sup><br>-2*10<sup>4</sup> ≤ target, arr1[i], arr2[i] ≤ 2*10<sup>4</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Facebook</code>&nbsp;<code>United Health Group</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Hash</code>&nbsp;<code>Data Structures</code>&nbsp;