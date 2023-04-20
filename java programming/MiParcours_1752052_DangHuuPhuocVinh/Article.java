
public class Article {
	private String nom;
	private String description;
	private double poidsExpedition;
	private double prix;
	
	Article(){
		this.nom = "";
		this.description = "";
		this.poidsExpedition = 0;
		this.prix = 0;
	}
	
	Article(String nom, String description, double poids, double prix){
		this.nom = nom;
		this.description = description;
		this.poidsExpedition = poid;
		this.prix = prix;
	}
	
	String getNom(){
		return this.nom;
	}
	
	String getDesc() {
		return this.description;
	}
	
	double getPoids() {
		return this.poidsExpedition;
	}
	
	double getPrix() {
		return this.prix;
	}
	
	String setNom(String nom) {
		return this.nom = nom;
	}
	
	String setDesc(String desc) {
		return this.description = desc;
	}
	
	double setPoids(double poids) {
		return this.poidsExpedition = poids;
	}
	
	double setPrix(double prix) {
		return this.prix = prix;
	}
	
	String toString(){
		System.out.print("Ten la: " + this.nom + "Descrition: " + this.description + "Poids: " + String.valueOf(this.poidsExpedition) + "Prix: " + String.valueOf(this.prix));
	}
}
