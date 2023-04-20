import java.util.Date;

public class Commande {
	private Date date;
	TypeEtat etat;
	
	double calMontanPaye() {
		Article art = new Article();
		CommandeDetaille comm = new CommandeDetaille();
		return art.getPrix() * comm.getQuantite();
	}
	
	double calPoidsTotal() {
		Article art = new Article();
		CommandeDetaille comm = new CommandeDetaille();
		return art.getPoids() * comm.getQuantite();
	}
	
	double calTotal() {
		CommandeDetaille comm = new CommandeDetaille();
		return comm.getQuantite();
	}
	
	void ajouterUneCommandeDetaille(CommandeDetaille cd) {
		CommandeDetaille comm = new CommandeDetaille();
		comm.quantite = cd.quantite;
	}
	
	void adjouterUnePaiement(Paiement p) {
		Paiement pai = new Paiement();
	}
	
}
