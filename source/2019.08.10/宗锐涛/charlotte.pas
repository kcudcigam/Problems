var
  i,j,n,x,y,z,t,l,o:longint;
  a,b,c:array[1..100000]of longint;
begin
  assign(input,'charlotte.in');
  reset(input);
  assign(output,'charlotte.out');
  rewrite(output);
  readln(t);
  for i:=1 to t do
    begin
      readln(n);
      for j:=1 to n do
        readln(a[j],b[j],c[j]);
      x:=0;
      y:=0;
      z:=0;
      l:=0;
      for j:=1 to n do
        begin
          o:=(a[j]-z-abs(b[j]-x)-abs(c[j]-y));
          if (o<0) or (o mod 2=1)
          then begin l:=1; break; end;
          x:=b[j];
          y:=c[j];
          z:=a[j];
        end;
      if l=1
      then writeln('No')
      else writeln('Yes');
    end;
  close(input);
  close(output);
end.