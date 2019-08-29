var
  i,j,k,n,m,num,x1,max,o,p:longint;
  a,l,r,x:array[1..10000]of longint;
begin
  assign(input,'stand.in');
  reset(input);
  assign(output,'stand.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to 5 do read(x[i]);
  k:=0;
  for i:=1 to n do
    begin
      readln(l[i],r[i]);
      if (l[i]<>1) or (r[i]<>m)
      then k:=1;
    end;
  if k=0
  then begin
         num:=0;
         for i:=1 to 5 do
           begin
             x1:=1;
             for j:=1 to i do
               x1:=x1*n;
             num:=num+x1*x[i];
           end;
         writeln(num); close(input); close(output); exit;
       end;
  fillchar(a,sizeof(a),0);
  k:=0;
  num:=0;
  while k<n do
    begin
      max:=0;
      for i:=1 to m do
        begin
          o:=0;
          for j:=1 to n do
            if (i>=l[j]) and (r[j]>=i) and (a[j]=0)
            then o:=o+1;
          if o>max
          then begin max:=o; p:=i; end;
        end;
      for i:=1 to n do
        if (p>=l[i]) and (p<=r[i]) and (a[i]=0)
        then begin a[i]:=1; k:=k+1; end;
      for i:=1 to 5 do
           begin
             x1:=1;
             for j:=1 to i do
               x1:=x1*max;
             num:=num+x1*x[i];
           end;
    end;
  writeln(num);
  close(input);
  close(output);
end.