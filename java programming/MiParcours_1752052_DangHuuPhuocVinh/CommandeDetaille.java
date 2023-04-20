
public class CommandeDetaille {
	private int quantite;
	
	CommandeDetaille(){
		this.quantite = 0;
	}
	
	CommandeDetaille(int quan){
		this.quantite = quan;
	}
	
	int getQuantite() {
		return this.quantite;
	}
	
	int setQuantite(int quan) {
		return this.quantite = quan;
	}
	
	double calSoustotal() {
		Article art = new Article();;
		return art.getNom() * this.quantite;
	}
	
	double calPoids() {
		Article art = new Article();
		return art.getPoids() * this.quantite;
	}
	
	
}
