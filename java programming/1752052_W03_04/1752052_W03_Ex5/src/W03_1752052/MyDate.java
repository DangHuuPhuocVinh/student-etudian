package W03_1752052;

class MyDate{
	int day;
	int month;
	int year;
	
	MyDate(){
		this.day = 0;
		this.month = 0;
		this.year = 0;
	}
	
	MyDate(int day, int month, int year){
		this.day = day;
		this.month = month;
		this.year = year;
	}
	
	int Compare(MyDate mydate) {
		if (this.year > mydate.year) {
			return 1;
		}
		
		if(this.year < mydate.year) {
			return -1;
		}
		
		if(this.year == mydate.year) {
			if(this.month > mydate.month) {
				return 1;
			}
			else if(this.month < mydate.month) {
				return -1;
			}
			else if(this.month == mydate.month)
			{
				if(this.day > mydate.day) {
					return 1;
				}
				else if(this.day < mydate.day) {
					return -1;
				}
				else if(this.day == mydate.day) {
					return 0;
				}
			}
		}
		
		return 2;
		
	}
	boolean checkLeapYear() {
		 if(this.year % 4 == 0)
	        {
	            if( this.year % 100 == 0)
	            {
	                if ( this.year % 400 == 0)
	                    return true;
	                else
	                    return false;
	            }
	            else
	                return true;
	        }
	        else
	            return false;
	}
	
	boolean isValid(){
		if(this.year > 0)
			return true;
		
		if(this.month > 0 && this.month < 12)
			return true;
		
		if(this.month == 1 || this.month == 3 || this.month == 5 || this.month == 7 || this.month == 8 || this.month == 10 || this.month == 12) {
			if(this.day > 0 && this.day < 32) {
				return true;
			}
			else
				return false;
		}

		if(this.month == 4 || this.month == 6 || this.month == 9 || this.month == 11) {
			if(this.day > 0 && this.day < 31) {
				return true;
			}
			else
				return false;
		}
		
		if(checkLeapYear() == true) {
			if(this.month == 2) {
				if(this.day == 29)
					return true;
				else 
					return false;
			}
		}
		
		if(this.month == 2) {
			if(this.day > 0 && this.day < 29)
				return true;
			else
				return false;
		}
		
		return false;
	}
	
	int calculateDistance(MyDate mydate)
	{
	    int time1, time2 , distance1, distance2;
	    if(this.month == 1 || this.month == 3 || this.month == 5 || this.month== 7|| this.month == 8|| this.month == 10 || this.month == 12)
	        time1 = this.month * 31;
	    else
	        if(this.month == 2)
	        {
	            if(this.year % 100 != 0 && this.year % 4 == 0 )
	                time1 = this.month * 29;
	            else 
	            	time1 = this.month * 28;
	        }
	        else 
	        	time1 = this.month * 30;
	    if(this.year % 100 != 0 && this.year % 4 == 0 )
	        time2 = this.year * 366;
	    else 
	    	time2 = this.year * 365;
	    
	    distance1 = this.day + time1 + time2;
	   
	    if(mydate.month == 1 || mydate.month == 3 || mydate.month == 5 || mydate.month == 7 || mydate.month == 8|| mydate.month == 10 || mydate.month == 12)
	        time1 = mydate.month * 31;
	    else
	        if(mydate.month == 2)
	        {
	            if(mydate.year % 100 != 0 && mydate.year % 4 == 0 )
	                time1 = mydate.month * 29;
	            else 
	            	time1 = mydate.month * 28;
	        }
	        else 
	        	time1 = mydate.month * 30;
	    if(mydate.year % 100 != 0 && mydate.year % 4 == 0 )
	        time2 = mydate.year * 366;
	    else 
	    	time2 = mydate.year * 365;
	    
	    distance2 = mydate.day + time1 + time2;
	    
	    return distance2 - distance1;
	}
	
	public String toString()
	{
		return String.valueOf(this.day) + "/" + String.valueOf(this.month) + "/" + String.valueOf(this.year);
	}
	
	public String toString(int n)
	{
		return String.valueOf(this.day) + "-" + String.valueOf(this.month) + "-" + String.valueOf(this.year);
	}
	
}