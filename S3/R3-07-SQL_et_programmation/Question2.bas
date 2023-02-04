'Créez une requête « R1_TD2 » qui récupère la liste des avions ainsi que leur capacité

Option Compare Database
Dim cn As ADOBD.Connection
Dim rs As New ADOBD.Recordset

Private Sub Form_Open(Cancel as Integer)
    Set objConn = CurrentProject.Connection
    'rs.Open "SELECT * FROM avion", objConn, adOpenStatic, adLockOptimistic
    rs.Open "R1_TD2", objConn, adOpenStatic, adLockReadOnly
End Sub

Private Sub DEBUT_Click()
    rs.MoveFirst
    If Not rs.EOF Then
        Text22.Value="L'avion " & rs.Fields("AVION").Value & " a une capacité de : " & rs.Field("capacite").Value
    End If
End Sub

'Procédure qui modifie en temps réel les coordonnées affichées quand on survole l'image "Carte_France.gif"
Private Sub Image1_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Text1.Value = X
    Text2.Value = Y
End Sub