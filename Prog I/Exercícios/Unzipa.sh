for f in *.zip;
    do new_dir="${f##*/}";
    new_dir="${new_dir%.*}"; 
    mkdir -p "$new_dir"; 
    unzip -d "$new_dir" -- "$f";
    rm "$f";
    done