<?php
  $resultJSON = array();

  @$url    = "http://aucoe.annauniv.edu/cgi-bin/result/cgrade.pl?regno=" . $_GET["regno"];
  $content = @file_get_contents($url);

  if(strpos($content, "is wrong!")) {
    echo '{"error": "Invalid Register Number"}';
  }
  else {
    $content     = strip_tags($content, "<table><tbody><tr><td>");
    $table_begin = strpos($content, '<table width="500" border="1" align="center">');
    $content     = substr($content, $table_begin);
    $content     = str_replace(substr($content, strpos($content, "</table>")), "", $content);

    $doc  = new DOMDocument('5.0', 'UTF-8');
    $doc->loadHTML($content);
    $rows = $doc->getElementsByTagName("tr");

    foreach($rows as $row) {
      $fields = $row->childNodes;

      $subject = trim($fields->item(0)->nodeValue);
      $grade = trim($fields->item(2)->nodeValue);

      $resultJSON[$subject] = $grade;
    }
    
    array_shift($resultJSON);
    echo json_encode($resultJSON);
  }
?>
