CREATE TRIGGER trigger_nbe_materiel
AFTER INSERT ON MATERIEL
WHEN new.IdCategorie = (SELECT IdCategorie FROM CATEGORIE WHERE CATEGORIE.IdCategorie = new.IdCategorie)
BEGIN
UPDATE CATEGORIE
SET NbeMateriel=NbeMateriel+1
WHERE CATEGORIE.IdCategorie = NEW.IdCategorie;
END;


CREATE TRIGGER trigger_rm_nbe_materiel
AFTER DELETE ON MATERIEL
WHEN old.IdCategorie =(SELECT IdCategorie FROM CATEGORIE WHERE CATEGORIE.IdCategorie = old.IdCategorie)
BEGIN
UPDATE CATEGORIE
SET NbeMateriel = NbeMateriel -1
WHERE CATEGORIE.IdCategorie = OLD.IdCategorie;
END;
