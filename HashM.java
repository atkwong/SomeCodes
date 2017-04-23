
/**
 * Write a description of class HashMap here.
 * 
 * @author:  atkwong
 * @version 2016
 */

import java.util.*;
public class HashM<K,V> extends HashMap<K,V> 
{
    public HashM(K[] keys, V[] values)
    {
        super();
        for (int c=0; c<keys.length; c++)
       { 
         put(keys[c], values[c]);
       }
    }
  
    public String toString()
    {
        Iterator<Entry<K,V>> mapIr = entrySet().iterator();
        StringBuilder mapDisplay = new StringBuilder();
        
         while (mapIr.hasNext())
        {
            Entry<K,V> mapEntry = mapIr.next();
            mapDisplay.append(mapEntry.getKey() + ": ");
            mapDisplay.append(mapEntry.getValue() + "\n");
      }
      return mapDisplay.toString();
    }
    
    public static void main(String[] args)
    {
        
        String[] topics = {"KCL","BodePlot","OpAmp","LPF","BPSK"};
        Integer[] randNo = {5,11,18,27,30};
        
        HashM<String,Integer> map = new HashM<String,Integer>(topics,randNo); 
        
        for (int i=0; i<topics.length; i++)
        {
            System.out.println("The corr. number of " + topics[i] + " is "+ map.get(topics[i]));
        }
        
        System.out.println(map.toString());
    }
}