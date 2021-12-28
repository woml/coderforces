针对最后所有层选择的组合方案，我们选择了一种和mcsoc不同的选择方案。在mcsoc中，所有层的权重是完全相同的，也就是每层的票数都是1，最后统计得票数最高的组合，作为最终的方案。但是，这样存在一定的问题，就是
```
\begin{algorithm}  
  \caption{Voting from multipe layers\label{fig:code3}}  
  \KwIn{$n$ is the number of CNN.\ $Layer\_solution[n]$ are the best solution for each layers.}    
  \KwOut{$final\_solution$ is the whole CNN solution.}    
Create a map VOTE$<solution,int>$,which is used to store voting results\; 
\For{$ i=0;i<n;i++$}  
{
VOTE[$Layer\_solution[i]$]++\;
}
$final\_solution$= the solution in VOTE with the most votes\;
return $final\_solution$\;  
\end{algorithm} 
```