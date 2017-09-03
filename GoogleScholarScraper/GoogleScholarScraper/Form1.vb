Public Class Form1
    Dim ScholarURL As String = "https://scholar.google.co.in/citations?user="

    Private Sub btnGo_Click(sender As Object, e As EventArgs) Handles btnGo.Click
        ScholarURL &= txtScholarID.Text ' Construct URL

        Try
            browser.Navigate(ScholarURL)
            Dim name = browser.Document.GetElementById("gsc_prf_in").InnerText

            MessageBox.Show(name)
        Catch ex As Exception
            MessageBox.Show("An Exception Occured!")
        End Try
    End Sub
End Class
