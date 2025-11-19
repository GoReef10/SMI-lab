Private Sub btnOpen_Click()
Dim intPortID As Integer

Dim lngStatus As Long
Dim iRet As Integer
Dim LastErr As String
intPortID = CInt(Worksheets("Control").Range("B2"))
lngStatus = CommOpen(intPortID, "\\.\COM" & CStr(intPortID), _
"baud=9600 parity=N data=8 stop=1")
If (lngStatus = 0) Then
Worksheets("Control").Range("B3") = "connected"
Worksheets("Control").btnRead.Enabled = True
Worksheets("Control").btnClose.Enabled = True
Worksheets("Control").btnOpen.Enabled = False
startrow = CInt(Worksheets("Control").Range("B5").Value)
Else
Worksheets("Control").Range("B3") = "not connected"
Worksheets("Control").btnRead.Enabled = False
Worksheets("Control").btnClose.Enabled = False
Worksheets("Control").btnOpen.Enabled = True
iRet = CommGetError(LastErr)
Call MsgBox(LastErr, vbCritical)
End If
End Sub

Private Sub btnRead_Click()
Dim intPortID As Integer
Dim lngStatus As Long
Dim temp As String
Dim strData As String
status = "read"
Worksheets("Control").btnStop.Enabled = True
Worksheets("Control").btnRead.Enabled = False
Worksheets("Control").btnDraw.Enabled = False
Worksheets("Control").btnClear.Enabled = False
currentrow = startrow
strData = ""
intPortID = CInt(Worksheets("Control").Range("B2").Value)
While (status = "read")
DoEvents
lngStatus = CommRead(intPortID, temp, 10)
temp = Replace(temp, vbCrLf, Chr(13))
temp = Replace(temp, Chr(10), "")

While (Len(temp) > 0)
DoEvents
If InStr(1, temp, Chr(13)) > 0 Then
strData = strData + Left(temp, InStr(1, temp,_
Chr(13)) - 1)
temp = Right(temp, Len(temp) - InStr(1, temp,_
Chr(13)))
Worksheets("Data").Range("B" & currentrow).Value =
strData
Worksheets("Data").Range("A" & currentrow).Value =
Time
Worksheets("Control").Range("B6").Value = currentrow
currentrow = currentrow + 1
strData = ""
Else
strData = strData + temp
temp = ""
End If
Wend
Wend
End Sub
Private Sub btnStop_Click()
Worksheets("Control").btnRead.Enabled = True
Worksheets("Control").btnStop.Enabled = False
Worksheets("Control").btnDraw.Enabled = True
Worksheets("Control").btnClear.Enabled = True
status = "stop"
End Sub

Private Sub btnClose_Click()
Dim intPortID As Integer
Dim lngStatus As Long
Dim iRet As Integer
Dim LastErr As String
intPortID = CInt(Worksheets("Control").Range("B2").Value)
lngStatus = CommClose(intPortID)
If (lngStatus = 0) Then
Worksheets("Control").Range("B3") = "not connected"
Worksheets("Control").btnRead.Enabled = False
Worksheets("Control").btnStop.Enabled = False
Worksheets("Control").btnClose.Enabled = False

Worksheets("Control").btnOpen.Enabled = True
Else
iRet = CommGetError(LastErr)
Call MsgBox(LastErr, vbCritical)
End If
lngStatus = CommSetLine(intPortID, LINE_RTS, False)
lngStatus = CommSetLine(intPortID, LINE_DTR, False)
End Sub