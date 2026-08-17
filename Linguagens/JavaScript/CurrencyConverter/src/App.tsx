import { useState } from 'react'
import Box from '@mui/material/Box';
import Card from '@mui/material/Card';
import CardActions from '@mui/material/CardActions';
import CardContent from '@mui/material/CardContent';
import Button from '@mui/material/Button';
import Typography from '@mui/material/Typography';

import './App.css'

function App() {

  return (
    <>
      <Card sx={{ minWidth: 275 }}>
        <CardContent>
          <Typography gutterBottom sx={{ color: 'text.secondary', fontSize: 14 }}>
            Currency Converter
          </Typography>
          <Typography variant="h5" component="div">
            From:
          </Typography>
          <Typography variant="h5" component="div">
            To:
          </Typography>
        </CardContent>
        <CardActions>
          <Button size="small">Convert</Button>
        </CardActions>
      </Card>
    </>
  )
}

export default App
