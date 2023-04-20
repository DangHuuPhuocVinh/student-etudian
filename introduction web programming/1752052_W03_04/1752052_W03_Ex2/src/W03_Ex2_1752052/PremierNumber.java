package W03_Ex2_1752052;

class PremierNumber {
	 boolean Verifier(int number){
		 if(number == 0 || number == 1) {
			 return false;
		 }
		  if(number == 2){
		   return true;
		  }
		  else {
		   for(int i = 2; i <= Math.sqrt(number); i++){
		    if(number % i == 0)
		     return false;
		   }
		  }
		  return true;
		 }
}
