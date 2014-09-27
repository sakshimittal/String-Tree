
Storing strings within a tree in a memory efficient manner 
-----------------------------------------------------------

In order to store strings efficiently and retrieve them very fast , we have to build a tree structure like explained below. The tree is supposed to store the strings within themselves. The tree should have 4 main methods exposed to the outside world i.e. users of the tree. 

	public boolean addString(String str);		- Return true if the string is added , false if it can not be added.(May be it already exists).

	public boolean deleteString(String str); 	- Returns true if the string is deleted properly, false if not. (May be the string is not found).

	public boolean findString(String str);		- Returns true if the string exists in the tree , false otherwise.

	public void printString();			- Prints the tree in a XML fashion. Mainly used to debug.



The way the tree works is as follows.

The tree has a root node called TreeGateway(TG). All the nodes above this are called StringNodes(SN). Each String node stores a String and references of its child nodes. It also stores a flag stating whether the String is what the user has specified.

Initially, when the tree is created, there is only the TG. Then say a String PAT is added to the tree. The way tree looks like is -

		T G
		 |
		 |
		S N ("PAT",true)

Now another String is added to the tree , say "PAN". Now the way the tree will look like is -

		T G
		 |
		 |
		S N ("PA",false)		Here I split the node such that the common part is kept in the 
		/ \				parent node and the rest is moved into two different nodes below.
  	       /   \				"PA" is not one of the strings that the user has entered, so the flag
	      /     \				is set to false.
	     /       \
     SN ("T",true)    SN ("N",true)

Now another string is added , say "PATTERN".

			T G
			 |
			 |
			S N ("PA",false)	Part of the string "PATTERN" is already found in the tree. So I add
			/ \			the remaining part below that. Both "PAT" & "PATTERN" are strings 
	  	       /   \			that the user has entered, so both have flag as true.
		      /     \
		     /       \
	     SN ("T",true)    SN ("N",true)
		   /
		  /
	 SN ("TERN",true)


Another String is added "PAINT".


				T G
				 |
				 |
			   S N ("PA",false)			Similar to above, PAINT is added below "PA".
			   /    |     \
			  /	|      \
			 /	|       \
			/ 	| 	 \
	  	       /   	|	  \
		      /     	|	   \
		     /       	|	    \
	     SN ("T",true)    	|   	    SN ("N",true)
		   /	     SN("INT",true)
		  /
	 SN ("TERN",true)

Now a string is deleted "PAT"

				T G
				 |
				 |
			   S N ("PA",false)			When "PAT" is deleted, the tree should look as if
			   /    |     \				it was never added. Since there are no other children 
			  /	|      \			of "T" node, the tree is collapsed till that point.
			 /	|       \
			/ 	| 	 \
	  	       /   	|	  \
		      /     	|	   \
		     /       	|	    \
	  SN ("TTERN",true)    	|   	    SN ("N",true)
		   	     SN("INT",true)
		  
Now a String is added "PAINING"

				T G
				 |
				 |
			   S N ("PA",false)
			   /    |     \
			  /	|      \
			 /	|       \
			/ 	| 	 \
	  	       /   	|	  \
		      /     	|	   \
		     /       	|	    \
	  SN ("TTERN",true)    	|   	    SN ("N",true)
		   	     SN("IN",false)
			      /    \
			     /      \
  			    /        \
			   /	      \
		SN("ING",true)	       SN("T",true)

Now a String is added "PAIN"

				T G
				 |
				 |
			   S N ("PA",false)			Here, "PAIN" is already present is the tree. It was
			   /    |     \				simply not identified as a user entered string. So
			  /	|      \			all I have to do is set the flag to identify it as a
			 /	|       \			user entered string.
			/ 	| 	 \
	  	       /   	|	  \
		      /     	|	   \
		     /       	|	    \
	  SN ("TTERN",true)    	|   	    SN ("N",true)
		   	     SN("IN",true)
			      /    \
			     /      \
  			    /        \
			   /	      \
		SN("ING",true)	       SN("T",true)



Delete String "PAINT"

				T G
				 |
				 |
			   S N ("PA",false)			Here the tree can not collapse although there is only
			   /    |     \				one child to the "IN" node. This is because "PAIN" needs
			  /	|      \			to be identified as a separate user word than "PAINING".
			 /	|       \
			/ 	| 	 \
	  	       /   	|	  \
		      /     	|	   \
		     /       	|	    \
	  SN ("TTERN",true)    	|   	    SN ("N",true)
		   	     SN("IN",true)
			      /
			     /
  			    /
			   /
		SN("ING",true)


Delete String "PAIN"


				T G
				 |
				 |
			   S N ("PA",false)			Now, I can collapse the tree as "PAIN" is no longer
			   /    |     \				a user entered string. So I do not need to identify it 
			  /	|      \			separately.
			 /	|       \
			/ 	| 	 \
	  	       /   	|	  \
		      /     	|	   \
		     /       	|	    \
	  SN ("TTERN",true)    	|   	    SN ("N",true)
		   	     SN("INING",true)


Add String "PEN"


				       T G
					|
					|
					|
				      SN ("P",false")
				      /	  \
				     /	   \
				    /	    \
				   /	     \
				  /	      \
				 /	       \
			   S N ("A",false)	SN ("EN", true)
			   /    |     \
			  /	|      \
			 /	|       \
			/ 	| 	 \
	  	       /   	|	  \
		      /     	|	   \
		     /       	|	    \
	  SN ("TTERN",true)    	|   	    SN ("N",true)
		   	     SN("INING",true)














		 