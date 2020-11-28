<?php
    
    $array = array(1,99,0,23,7,42,56,18,5,9,40);
    $arraySize = count($array);   	

	for ($i = $arraySize - 1; $i >= 1; $i--)
	{
		for ($j = 0; $j < $i; $j++)
		{			
			if ($array[$j] > $array[$j + 1])
			{
				$aux = $array[$j];
				$array[$j] = $array[$j + 1];
				$array[$j + 1] = $aux;
			}
		}
    }
    $a=0;
    while($a < $arraySize){
        echo $array[$a], " ";
        
        $a++;
    }
    echo " \n"




?>