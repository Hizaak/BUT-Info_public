' Chaque clic sur Lecture : une procédure qui lit la 1 ère agence de la base, passe à l’agence suivante, et affiche
la ville dans une boîte de dialogue
Private Sub LECTURE Click ()
Dim db As DAO.Database
Dim rs As DAO.Recordset
Set db = CurrentDb ()
Set rs = db.OpenRecordset ("Select * From AGENCE", dbopenDynaset)
If Not rs.EOF Then
    MsgBox rs ("Ville")
    rs.MoveNext
End If
End sub

rs.MoveNext
End If
End sub

'chaque double click sur insertion : Procedure qui insère dans la table AGENCE une nouvelle ligne ("AG007","TOURS")
Private Sub INSERTION_DblClick()
Dim db As DAO.Database
Dim rs As DAO.Recordset
Set db = CurrentDb ()
Set tb_client = db.OpenRecordset ("AGENCE", dbopenDynaset)
tb_client.AddNew
tb_client ("Code") = "AG007"
tb_client ("Ville") = "TOURS"
rs.Update
End Sub

'chaque mouvement de la souris au dessus de Modification : une procédure qui modifie la ville de « TOURS » par « POITIERS »
Private Sub MODIFICATION_MouseMove(Button as Integer, Shift as Integer, X as Single, Y as Single)
Dim db As DAO.Database
Dim tb_client As DAO.Recordset
Set db = CurrentDb ()
Set tb_client = db.OpenRecordset ("Select * From AGENCE", dbopenDynaset)
While Not rs.EOF
    If tb_client ("Ville") = "TOURS" Then
        tb_client.Edit
        tb_client ("Ville") = "POITIERS"
        tb_client.Update
    End If
End While
End Sub

'chaque clic sur Suppression : une procédure qui supprime l’agence de POITIERS de la base
Private Sub SUPPRESSION_Click()
Dim db As DAO.Database
Dim tb_client As DAO.Recordset
Set db = CurrentDb ()
Set tb_client = db.OpenRecordset ("Select * From AGENCE", dbopenDynaset)
While Not tb_client.EOF
    If tb_client ("Ville") = "POITIERS" Then
        tb_client.Delete
    End If
    tb_client.MoveNext
End While
End Sub

'Une procédure permettant de se positionner au début des enregistrements de la requête « R1_TD2 »
Private Sub DEBUT_Click()
Dim db As DAO.Database
Dim rs As DAO.Recordset
Set db = CurrentDb ()
Set rs = db.OpenRecordset ("R1_TD2", dbopenDynaset)
rs.MoveFirst
End Sub

'Insérer une question dans la table question
Private Sub INSERTION_Click()
Dim db As DAO.Database
Dim rs As DAO.Recordset
Set db = CurrentDb ()
Set rs = db.OpenRecordset ("QUESTION", dbopenDynaset)
rs.AddNew
rs ("Code") = "Q007"
rs ("Question") = "Quelle est la couleur du cheval blanc d'Henri IV ?"
rs ("Reponse") = "Blanc"
rs.Update
End Sub

'Change l'attribut 'couleur' de l'avion de la table AVION ayant comme code 'AV001' en 'rouge'
Private Sub MODIFICATION_Click()
Dim db As DAO.Database
Dim rs As DAO.Recordset
Set db = CurrentDb ()
Set rs = db.OpenRecordset ("AVION", dbopenDynaset)
While Not rs.EOF
    If rs ("Code") = "AV001" Then
        rs.Edit
        rs ("Couleur") = "rouge"
        rs.Update
    End If
    rs.MoveNext
End While
End Sub

'Une procédure permettant de se déplacer vers l’enregistrement précédent de la requête « R1_TD2 »
Private Sub PRECEDENT_Click()
Dim db As DAO.Database
Dim rs As DAO.Recordset
Set db = CurrentDb ()
Set rs = db.OpenRecordset ("R1_TD2", dbopenDynaset)
rs.MovePrevious
End Sub

'Une procédure permettant de se déplacer vers l’enregistrement suivant de la requête « R1_TD2 »
Private Sub SUIVANT_Click()
Dim db As DAO.Database
Dim rs As DAO.Recordset
Set db = CurrentDb ()
Set rs = db.OpenRecordset ("R1_TD2", dbopenDynaset)
rs.MoveNext
End Sub

'Une procédure permettant de se positionner à la fin des enregistrements de la requête « R1_TD2 »
Private Sub FIN_Click()
Dim db As DAO.Database
Dim rs As DAO.Recordset
Set db = CurrentDb ()
Set rs = db.OpenRecordset ("R1_TD2", dbopenDynaset)
rs.MoveLast
End Sub

'récupérer les informations de l’enregistrement en cours et actualisez la valeur de l’étiquette « Etiq »
Private Sub ACTUALISATION_Click()
Dim db As DAO.Database
Dim rs As DAO.Recordset
Set db = CurrentDb ()
Set rs = db.OpenRecordset ("R1_TD2", dbopenDynaset)
If Not rs.EOF Then
    Etiq.Caption = rs ("Nom") & " " & rs ("Prenom") & " " & rs ("Ville")
End If
End Sub
