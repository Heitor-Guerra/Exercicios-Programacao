from django.db import models


class Currency(models.Model):
    name = models.CharField(max_length=200, null=False)
    acronym = models.CharField(max_length=3, unique=True)
    symbol = models.CharField(max_length=10, blank=True)
    usd_rate = models.DecimalField(max_digits=10, decimal_places=6)

    class Meta:
        verbose_name = "Currency"  # Singular name
        verbose_name_plural = "Currencies"  # Plural name
        ordering = ["acronym"]  # Default ordering
        db_table = "currencies"  # Table name
