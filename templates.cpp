//Single class for multiple datatypes , datatype is provided during object making


template <typename T> //T is now temporary datatype
//if we want x and y both of diff datatype the use
//template <typename T, typename V>
//Pair<int,double> p3 usdd as
//where V is new temp datatype for y 
//we can do same for more thn two or three datatypes , like triplets
class Pair{
	T x; 
	T y;
	public :
	void setX(T x){
		this -> x = x;
	}

	T getX(){
		return x; 
	}

	void setY(T y){
		this -> y = y;
	}

	T getY(){
		return y;
	}
};
