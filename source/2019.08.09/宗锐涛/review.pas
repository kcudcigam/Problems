var
  i,j,n,m,l:longint;
  y,k,o:int64;
  a:array[1..1000]of int64;
  v:array[1..1000]of longint;
begin
  assign(input,'review.in');
  reset(input);
  assign(output,'review.out');
  rewrite(output);
  readln(y);
  k:=1;
  n:=2;
  while k*2<=y do
    begin
      k:=k*2;
      n:=n+1;
    end;
  if y>k
  then begin n:=n+1; k:=k*2-y; end
  else k:=0;
  fillchar(v,sizeof(v),0);
  a[1]:=1;
  a[2]:=1;
  for i:=3 to n-1 do
    a[i]:=a[i-1]*2;
  o:=(n*(n-1)) div 2;
  for i:=n-1 downto 1 do
    begin
      if k>=a[i]
      then begin k:=k-a[i]; v[i]:=1; o:=o-1; end;
    end;
  writeln(n,' ',o);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        if (j<>n) or (v[i]<>1)
        then writeln(i,' ',j);
      end;
  close(input);
  close(output);
end.