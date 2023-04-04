Param(
        [String]$Att,
        [String]$Subj,
        [String]$Body
      )

Function Send-Email
{
    Param(
            [Parameter(`
            Mandatory=$true)]
            [String]$To,
            [Parameter(`
            Mandatory=$true)]
            [String]$From,
            [ Parameter(`
            Mandatory=$true)]
            [String]$Password,
            [ Parameter(`
            Mandatory=$true)]
            [String]$Subject,
            [ Parameter(`
            Mandatory=$true)]
            [String]$Body,
            [ Parameter(`
            Mandatory=$true)]
            [String]$attachment
    )

    try
     {
    $Msg = New-Object System.Net.Mail.MailMessage($From, $To, $Subject, $Body)
    $Srv = "smtp.gmail.com"
    if ($attachment -ne $null)
           {
             try
             {
             $attachment = $attachment -split ("\:\:");

             ForEach($val in $attachment)
              {
                 $attachment = New-Object System.Net.Mail.Attachment($val)
                 $Msg.Attachments.Add($attach)
              }
             }
             catch 
             {
             exit 2 ; 
             }
             $client = New-Object Net.Mail.SmtpClient($Srv,587)
             $client.EnableSsl = $true
             $client.Credentials = New-Object System.Net.NetworkCredential($From.Split("@")[0],$Password);
             $Client.Send($Msg)
             Remove-Variable -Name Client
             Remove-Variable -Name Password
             exit 7 ;
     
           }
    }
    catch {
    exit 3 ; 
    }
    try{
    Send-Email
            -attachment $attach
            -To "our.destination@gmail.com"
            -Body $Body
            -Subject $Subject
            -password "tralalal"
            -From "Our.sender@gmail.com"
      }
         catch
         {
         exit 4 ; 
         }

}
