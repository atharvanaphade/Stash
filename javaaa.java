import java.io.*;

public class javaa {
	class parent{
		int i = 0;
		public void sub(String str) {
			i = 68;
		}
	}

	class child extends parent{
		public void subb(){
			i = 0;
		} 
	}

	public static void main (String[] args) {
		child obj = new child();
		child.subb();
	}
}